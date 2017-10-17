#ifndef HASPTR_H
#define HASPTR_H

#include <string>

class HasPtr{
public:
    HasPtr(const std::string &s = std::string()): 
         cnt(0), p(new std::string(s)), use(new std::size_t(1)) {}
    HasPtr(const HasPtr& other);

    HasPtr& operator=(const HasPtr& rhs);
    ~HasPtr();

private:
    int cnt;
    std::string *p;
    std::size_t *use;
};

#endif
