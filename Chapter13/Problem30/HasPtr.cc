#include "HasPtr.h"
#include <iostream>

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


void
swap(HasPtr &lhs, HasPtr &rhs){

    cout<<"swapping \"" << *lhs.p << "\" and \"" << *rhs.p <<"\"" << endl;

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
