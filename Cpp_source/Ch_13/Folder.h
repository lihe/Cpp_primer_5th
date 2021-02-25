//
// Created by Leslie on 2021/2/25.
//

#ifndef CPP_FOLDER_H
#define CPP_FOLDER_H

#include <iostream>
#include <string>
#include <set>
#include "Message.h"

using namespace std;

class Folder {
    friend void swap(Message &, Message &);
    friend class Message;

public:
    Folder() = default;

    Folder(const Folder &);
    Folder& operator = (const Folder &);
    ~Folder();

    void save(Message &);
    void remove(Message &);

private:
    set<Message*> msgs;
    void add_to_Messages(const Folder &);
    void remove_from_Msgs();
    void addMsg(Message *m) { msgs.insert(m); }
    void remMsg(Message *m) { msgs.erase(m); }
    void move_Messages(Folder *);
};


#endif //CPP_FOLDER_H
