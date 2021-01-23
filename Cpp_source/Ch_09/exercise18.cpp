//
// Created by Leslie on 2021/1/23.
//

#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<string> sd;      // deque在首尾位置添加新元素性能很好
    string word;
    while (cin >> word){
        sd.push_back(word);
    }

    for (auto si = sd.cbegin(); si != sd.cend(); si++){
        cout << *si << endl;
    }
    return 0;
}