//
// Created by Leslie on 2021/1/24.
//

#include <iostream>
#include <string>
#include <string>

using namespace std;

void replace_string(string &s, const string &oldVal, const string &newVal){
    auto len = oldVal.size();

    if (!len)     // 要查找的字符串为空
        return;

    auto iter = s.begin();
    while (iter <= s.end() - len){     // 末尾少于odlVal的长度无需查找
        auto iter1 = iter;
        auto iter2 = oldVal.begin();
        while (iter2 != oldVal.end() && *iter1 == *iter2){
            iter1 ++;
            iter2 ++;
        }
        if (iter2 == oldVal.end()){
            iter = s.erase(iter, iter1);   // 删除s中与oldVal相同的部分
            if (!newVal.empty()){          // 替换字串是否为空
                iter2 = newVal.end();      // 从后向前逐个插入newVal字符helloworld
                do {
                    iter2 --;
                    iter = s.insert(iter, *iter2);
                } while (iter2 > newVal.begin());
            }
            iter += newVal.size();
        }
        else
            iter ++;
    }
}

int main(int argc, char *argv[]){
    string s("The thru tho!");
    replace_string(s, "thru", "through");
    cout << s << endl;

    replace_string(s, "tho", "though");
    cout << s << endl;

    replace_string(s, "through", "");
    cout << s << endl;
    return 0;
}
