#ifndef MESSAGE_H
#define MESSAGE_H

#include <set>
#include <string>

class Folder;

class Message{
    friend void swap(Message&, Message&);
    friend class Folder;
public:

    explicit Message(const std::string &str=""): contents(str) {}
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();

    void save(Folder&);
    void remove(Folder&);

private:
    std::string contents;
    std::set<Folder*> folders;

    // 将本Message添加到指向参数的Folder中
    void addToFolder(const Message&);
    void removeFromFolder();

    void swap(Message &rhs);
};


#endif

