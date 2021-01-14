#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void basic_getline(){
    string line;
    while (getline(cin, line)){
        cout << line << endl;
    }
}

void basic_test(){
    string s = "Test String";
    cout << "Size: " << s.size() << endl
         << "Empty: " << s.empty() << endl;
    for (auto c : s){
        cout << c << endl;
    }
}

void basic_string(){
    string str = "some string";
    decltype(str.size()) punct_cnt = 0;  // 标点符号的数量
    for (auto c : str){
        if (ispunct(c))
            punct_cnt++;
    }
    cout << punct_cnt << " punctuation characters in " << s << endl;
}