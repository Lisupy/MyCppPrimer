#include "HasPtr.h"
#include <iostream>

using namespace std;

HasPtr::HasPtr(const HasPtr& other):
    cnt(other.cnt), p(other.p), use(other.use){
        ++(*use);
}

HasPtr::~HasPtr(){
    if(use){
        --(*use);
        if (0 == *use){
            delete p;
            delete use;
        }
    }
}

HasPtr::HasPtr(HasPtr &&rhs):
    cnt(rhs.cnt), p(rhs.p), use(rhs.use)
{
    rhs.cnt = 0;
    rhs.p = nullptr;
    rhs.use = nullptr;
}


HasPtr&
HasPtr::operator=(HasPtr rhs){
    swap(*this, rhs);
    return *this;
}


void
swap(HasPtr &lhs, HasPtr &rhs){

    using std::swap;
    swap(lhs.p, rhs.p);
    swap(lhs.use, rhs.use);
    swap(lhs.cnt, rhs.cnt);
}

ostream&
print(ostream& os, const HasPtr &ptr){
    os << *ptr.p;
    return os;
}
