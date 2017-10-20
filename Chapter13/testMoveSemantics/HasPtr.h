#ifndef HASPTR_H
#define HASPTR_H

#include <string>
#include <ostream>

class HasPtr{
public:
    friend void swap(HasPtr&, HasPtr&);
    friend std::ostream& print(std::ostream&, const HasPtr&);
    HasPtr(const std::string &s = std::string()): 
         cnt(0), p(new std::string(s)), use(new std::size_t(1)) {}
    HasPtr(const HasPtr& other);
    HasPtr(HasPtr &&rhs);

    HasPtr& operator=(HasPtr rhs);
    ~HasPtr();

private:
    int cnt;
    std::string *p;
    std::size_t *use;
};

#endif
