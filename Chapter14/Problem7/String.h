#ifndef STRING_H
#define STRING_H

#include <memory>
#include <utility>
#include <ostream>

class String{
    friend std::ostream& operator<<(std::ostream&, const String&);
public:
    String():String("") {}
    String(const char*);
    ~String();
    String(const String&);
    String(String &&rhs) noexcept;
    String &operator=(const String&);
    String &operator=(String &&rhs) noexcept;

    std::size_t length() const { return end - elements - 1; }
    std::size_t capacity() const { return end - elements; }
    const char* c_str() const { return elements; }

private:
    auto alloc_n_copy(const char*, const char*) -> std::pair<char*, char*>;
    void range_initializer(const char*, const char*);
    void free();

private:
    char* elements;
    char* end;
    static std::allocator<char> alloc;
};


#endif
