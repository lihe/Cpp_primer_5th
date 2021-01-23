//
// Created by Leslie on 2021/1/23.
//

#include <iostream>
#include <list>

using namespace std;

int main() {
    list<string> sl;   // 对list来说，在任何位子添加元素都有很好的性能
    string word;

    while (cin >> word){
        sl.push_back(word);
    }

    for (auto &s : sl){
        cout << s << endl;
    }
}