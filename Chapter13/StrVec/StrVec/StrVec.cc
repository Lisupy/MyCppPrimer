#include "StrVec.h"
#include <string>
#include <memory>
#include <utility>
#include <algorithm>

using namespace std;

// 静态成员需要在类外定义
std::allocator<string> StrVec::alloc;


StrVec::StrVec(const initializer_list<string> &il):
    elements(nullptr), first_free(nullptr), cap(nullptr)
{
    auto newspace = alloc_n_copy(il.begin(), il.end());
    elements = newspace.first;
    first_free = cap = newspace.second;
}

StrVec::StrVec (const StrVec& other){
    auto newdata = alloc_n_copy(other.elements, other.first_free);
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec& StrVec::operator=(const StrVec &rhs){
    if(&rhs == this){
        auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
        free();
        elements = newdata.first;
        first_free = cap = newdata.second;
    }
    return *this;
}

StrVec::~StrVec(){
    free();
}

void
StrVec::push_back(const string &s){
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

void 
StrVec::chk_n_alloc(){
    if(size() == capacity())
        reallocate();
}

void
StrVec::free(){
    if(elements){
        for_each(elements, first_free, [this](string &rhs){alloc.destroy(&rhs);});
        alloc.deallocate(elements, cap-elements);
    }
}

void 
StrVec::reallocate(){
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);

    auto dest = newdata;
    auto elem = elements;    
    for(size_t i=0; i!=size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

pair<string*, string*>
StrVec::alloc_n_copy(const string *b, const string *e){
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void
StrVec::reserve(size_t n){
    if(n <= capacity())
        return;

    auto newspace = alloc.allocate(n);

    auto dest = newspace;
    auto elem = elements;
    for(size_t i=0; i!=size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newspace;
    first_free = dest;
    cap = elements + n;
}

inline void
StrVec::resize(size_t n){
    resize(n, string());
}

void
StrVec::resize(size_t n, const string& s){
    auto newspace = alloc.allocate(n);
    auto dest = newspace;
    auto elem = elements;   
    size_t i = 0;
    for(; i != size()&& i != n; ++i)
        alloc.construct(dest++, std::move(*elem++));
    
    if(n > size()){
        for(; i!=n; ++i)
            alloc.construct(dest++, s);
    }
    free();
    elements = newspace;
    first_free = dest;
    cap = elements + n;
}
