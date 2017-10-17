#include "HasPtr.h"

using namespace std;

HasPtr::HasPtr(const HasPtr& other):
    cnt(other.cnt), p(other.p), use(other.use){
        ++(*use);
}

HasPtr::~HasPtr(){
    --(*use);

    if (0 == *use){
        delete p;
        delete use;
    }
}

HasPtr&
HasPtr::operator=(const HasPtr& rhs){
    if(this != &rhs){
        ++*(rhs.use);
        --(*use);
        if(0 == *use){
            delete p;
            delete use;
        }
        cnt = rhs.cnt;
        p = rhs.p;
        use = rhs.use;
    }
    return *this;
}
