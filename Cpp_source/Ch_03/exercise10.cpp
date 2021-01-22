//
// Created by Leslie on 2021/1/22.
//

#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cout << "请输入一个字符串，最好包含某些标点符号！" << endl;
    getline(cin, s);
    for (auto c : s){
        if (!ispunct(c))
            cout << c;
    }
    cout << endl;
    return 0;
}