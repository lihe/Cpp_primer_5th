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
    set<Message*> msgs;                                // 文件夹中的所有Message指针
    void add_to_Messages(const Folder &);              // 将此folder添加到每个message中
    void remove_from_Msgs();                           // 从每个message中删光此folder
    void addMsg(Message *m) { msgs.insert(m); }
    void remMsg(Message *m) { msgs.erase(m); }
    void move_Messages(Folder *);
};

inline
Folder::Folder(const Folder &f) : msgs(f.msgs) {
    add_to_Messages(f);
}

inline
void Folder::add_to_Messages(const Folder &f) {
    for (auto msg : f.msgs)
        msg->addFldr(f);
}

inline
void Folder::remove_from_Msgs() {
    while (!msgs.empty())
        (*msgs.begin())->remove(*this);   // 将这个folder从它所有Message中删除
}

Folder::~Folder() {
    remove_from_Msgs();
}

inline
Folder& Folder::operator=(const Folder &f) {
    remove_from_Msgs();
    msgs = f.msgs;
    add_to_Messages(f);
    return *this;
}

void swap(Message &lhs, Message &rhs) {
    using std::swap;

    // 将每个Message的指针从它原来所在的folder中删除
    for (auto f : lhs.folders)
        f->remMsg(&lhs);

    for (auto f : rhs.folders)
        f->remMsg(&rhs);

    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);

    // 将每个Message的指针添加到新的Folder中
    for (auto f : lhs.folders)
        f->addMsg(&lhs);

    for (auto f : rhs.folders)
        f->addMsg(&rhs);

}


#endif //CPP_FOLDER_H
