#include "String.h"
#include <memory>
#include <cstring>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

std::allocator<char> String::alloc;


String::String(const char* cstr)
{
    auto sl = cstr;
    while(*sl)
        ++sl;
    auto newdata = alloc_n_copy(cstr, ++sl);
    elements = newdata.first;
    end = newdata.second;
}

String::String(const String& other)
{
    auto newdata = alloc_n_copy(other.elements, other.end);
    elements = newdata.first;
    end = newdata.second;
    clog << "copy constructor" << endl;
}

String::~String()
{
    free();
}


String::String(String &&rhs) noexcept:
    elements(rhs.elements), end(rhs.end)
{
    rhs.elements = nullptr;
    rhs.end = nullptr;
    clog << "move constructor" << endl;
}

String& String::operator=(const String& rhs)
{
    if(&rhs != this){
        auto newstr = alloc_n_copy(rhs.elements, rhs.end);
        free();
        elements = newstr.first;
        end = newstr.second;
    }
    clog << "copy-assignment" << endl;
    return *this;
}


String& String::operator=(String &&rhs) noexcept
{
    if(&rhs != this){
        free();
        elements = rhs.elements;
        end = rhs.end;
        elements = end = nullptr;
    }
    clog << "move assignment" << endl;
    return *this;
}


pair<char*, char*>
String::alloc_n_copy(const char *b, const char *e)
{
    auto p = alloc.allocate(e-b);
    return {p, uninitialized_copy(b, e, p)};
}

void
String::free()
{
    if(elements){
        for_each(elements, end, [](char &c){ alloc.destroy(&c); });
        alloc.deallocate(elements, end-elements);
    }
}


ostream&
operator<<(ostream &os, const String &s)
{
    os << s.elements;
    return os;
}
