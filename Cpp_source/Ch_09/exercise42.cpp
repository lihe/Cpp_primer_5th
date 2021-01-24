//
// Created by Leslie on 2021/1/24.
//

#include <iostream>
#include <string>
using namespace std;

// 使用reserve为string分配一百个字符的空间，然后逐个读取字符
void input_string(string &s){
    s.reserve(100);
    char c;
    while (cin >> c){
        s.push_back(c);
    }
}

int main(int argc, char *argv[]){
    string s;
    input_string(s);
    cout << s << endl;
    return 0;
}
