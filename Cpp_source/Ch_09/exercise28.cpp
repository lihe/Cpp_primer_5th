//
// Created by Leslie on 2021/1/23.
//

#include <iostream>
#include <forward_list>

using namespace std;

void test_and_insert(forward_list<string> &slist, const string &s1, const string &s2){
    auto prev = slist.before_begin();
    auto curr = slist.begin();

    bool insert = false;

    while (curr != slist.end()) {
        if (*curr == s1) {
            curr = slist.insert_after(curr, s2);
            insert = true;
        }
        else{}
        prev = curr;
        curr ++;
    }

    if (!insert)
        slist.insert_after(prev, s2);
}

int main(int argc, char *argv[]){
    forward_list<string> slist{"Hello", "!", "world", "!"};
    test_and_insert(slist, "hello", "你好");
    for (const auto &iter : slist){
        cout << iter << endl;
    }

    test_and_insert(slist, "Bye", "再见");
    for (const auto &iter : slist){
        cout << iter << endl;
    }

    return 0;
}
