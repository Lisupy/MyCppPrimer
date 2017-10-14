#ifndef HASPTR_H
#define HASPTR_H

#include <string>

class HasPtr{
public:
    HasPtr(): cnt(0), p(nullptr) {}
    HasPtr(const HasPtr& other): cnt(other.cnt), p(new std::string(*other.p)) {}

    HasPtr& operator=(const HasPtr& rhs){
        if (&rhs != this){
            auto new_p = new std::string(*rhs.p);
            delete p;
            p = new_p;
            cnt = rhs.cnt;
        }
        return *this;
    }

    ~HasPtr(){
        delete p;
    }

private:
    int cnt;
    std::string *p;
};

#endif
