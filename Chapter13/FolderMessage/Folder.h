#ifndef FOLDER_H
#define FOLDER_H

#include "Message.h"
#include <set>


class Folder{
    friend void swap(Folder&, Folder&);
public:
    Folder() = default;
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();

    void addMsg(Message*);
    void remMsg(Message*);

private:
    std::set<Message*> messages;

    void addToMessage(const Folder&);
    void removeFromMessage();

    void swap(Folder &);
};

#endif
