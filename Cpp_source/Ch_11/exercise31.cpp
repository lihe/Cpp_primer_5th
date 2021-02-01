//
// Created by Leslie on 2021/1/31.
//

#include <iostream>
#include <list>
#include <map>
#include <sstream>

using namespace std;

void remove_author(multimap<string, string> &books, const string &author){
    auto pos = books.equal_range(author);
    if (pos.first == pos.second){
        cout << "没有" << author << "这个作者" << endl;
    }
    else
        books.erase(pos.first, pos.second);
}

void print_books(multimap<string, string> &boos){
    cout << "当前的书目包括：" << endl;
    for (const auto &book : boos){
        cout << book.first << "： 《" << book.second << "》" << endl;
    }
    cout << endl;
}

int main(int argc, char *argv[]){
    multimap<string, string> books;
    books.insert({"Barth John", "Sot-Weed Factor"});
    books.insert({"Barth John", "Lost in the Funhouse"});
    books.insert({"金庸", "射雕英雄传"});
    books.insert({"金庸", "笑傲江湖"});

    print_books(books);
    remove_author(books, "zhang");
    remove_author(books, "金庸");
    print_books(books);
    return 0;
}