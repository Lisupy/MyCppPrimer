#include "Message.h"
#include "Folder.h"
#include <set>
#include <string>

using std::set;
using std::string;


Message::Message(const Message& other): 
    contents(other.contents), folders(other.folders)
{   
    addToFolder(*this);
}

Message::~Message()
{
    removeFromFolder();    
}


Message& Message::operator=(const Message &rhs)
{
    if(this != & rhs){
        removeFromFolder();
        contents = rhs.contents;
        folders = rhs.folders;
        addToFolder(rhs);
    }
    return *this;
}

void
Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void
Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void
Message::addToFolder(const Message &m)
{
    for(auto f: m.folders)
        f->addMsg(this);
}


void
Message::removeFromFolder()
{
    for(auto f: folders)
        f->remMsg(this);
}


void
Message::swap(Message &rhs)
{
    using std::swap;
    rhs.removeFromFolder();
    this->removeFromFolder();

    swap(contents, rhs.contents);
    swap(folders, rhs.folders);

    rhs.addToFolder(rhs);
    this->addToFolder(*this);
}

void
swap(Message &lhs, Message &rhs)
{
    lhs.swap(rhs);
}
