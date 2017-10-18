#ifndef STRVEC_H
#define STRVEC_H

#include <string>
#include <memory>
#include <utility>

class StrVec{
public:
    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const std::initializer_list<std::string>&);
    StrVec(const StrVec&);  // ctor
    StrVec &operator=(const StrVec&); // asign op
    ~StrVec();

    void push_back(const std::string&);
    void reserve(std::size_t);  // 预留多少空间
    void resize(std::size_t);
    void resize(std::size_t, const std::string&);
    std::size_t size() const { return first_free - elements;}
    std::size_t capacity() const {return cap - elements; }
    std::string *begin() const {return elements;}
    std::string *end() const {return first_free;}

private:
    static std::allocator<std::string> alloc;

    std::string *elements;
    std::string *first_free;
    std::string *cap;


    // 保证StrVec至少有一个容纳新元素的空间,如果没有就调用reallocate
    void chk_n_alloc();
    // 销毁构造的元素并释放内存
    void free();
    // 在内存用完时为StrVec分配新内存
    void reallocate();
    // 分配内存,并拷贝一个给定范围中的元素
    auto alloc_n_copy(const std::string*, const std::string*) -> std::pair<std::string*, std::string*>;
};

#endif
