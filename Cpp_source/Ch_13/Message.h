//
// Created by Leslie on 2021/2/25.
//

#ifndef CPP_MESSAGE_H
#define CPP_MESSAGE_H

#include <iostream>
#include <string>
#include <set>
#include "Folder.h"

using namespace std;

class Message {
    friend void swap(Message &, Message &);
    friend class Folder;

public:
    explicit Message(const string &str = "") : contents(str) {}

    Message(const Message &);                  // 拷贝构造函数
    Message& operator = (const Message &);     // 拷贝赋值运算符
    Message(Message &&);
    Message& operator=(Message &&);
    ~Message();

    // 从给定的Folder中添加\删除Message
    void save(Folder &);
    void remove(Folder &);

private:
    string contents;              // 实际消息文本
    set<Folder*> folders;         // 包含本Message的Folder

    // 考本构造函数、拷贝赋值运算符和析构函数所使用的工具函数
    // 将本Message添加到指向参数的Folder中
    void add_to_Folders(const Message &);
    void remove_from_Folders();

    //
    void move_Folders(Message *);

    void addFldr(Folder *f) { folders.insert(f); }
    void remFldr(Folder *f) { folders.erase(f); }
};

inline
Message& Message::operator=(Message &&rhs) {
    if (this != rhs) {                           // 检查自赋值情况
        remove_from_Folders();
        contents = std::move(rhs.contents);      // 移动赋值运算符
        move_Folders(&rhs);
    }
    return *this;
}

inline
Message::Message(Message &&m) : contents(std::move(m.contents)) {
    move_Folders(&m);      // 移动folders并更新Folder指针
}

inline
void Message::move_Folders(Message *m) {
    folders = std::move(m->folders);  // 使用set的移动赋值运算符
    for (auto f : folders){           // 对每个Folder
        f->remMsg(m);                 // 从Folder中删除旧Message
        f->addMsg(this);              // 将本Message添加到Folder中
    }
    m->folders.clear();
}

inline
void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}

inline
void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
}

inline
void Message::add_to_Folders(const Message &m) {
    for (auto f : m.folders)
        f->addMsg(this);   // 对每个包含m的Folder向该Folder添加一个指向本Message的指针
}

inline
Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
    add_to_Folders(m);         // 将本消息添加到指向m的folder中
}

inline
void Message::remove_from_Folders() {
    for (auto f : folders)
        f->remMsg(this);
}

Message::~Message() {
    remove_from_Folders();
}

Message& Message::operator=(const Message &rhs) {
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);     // 将rhs添加到那些Folder中
    return *this;
}

#endif //CPP_MESSAGE_H
