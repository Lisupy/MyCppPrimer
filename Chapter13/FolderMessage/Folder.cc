#include "Message.h"
#include "Folder.h"

#include<set>
#include<string>

using std::set;
using std::string;

Folder::Folder(const Folder& other): messages(other.messages)
{ 
    addToMessage(other);
}

Folder&
Folder::operator=(const Folder& rhs)
{
    if(this != &rhs){
        removeFromMessage();
        messages = rhs.messages;
        addToMessage(rhs);
    }
    return *this;
}

Folder::~Folder(){
    removeFromMessage();
}


void
Folder::addToMessage(const Folder& f)
{
    for(auto m: f.messages){
        m->folders.insert(this);
    }
}

void
Folder::removeFromMessage()
{
    for(auto m: messages){
        m->folders.erase(this);
    }
}


void
swap(Folder& lhs, Folder& rhs)
{
    lhs.swap(rhs);    
}

void
Folder::swap(Folder& rhs){
    using std::swap;
    removeFromMessage();
    swap(messages, rhs.messages);
    addToMessage(rhs);
}
