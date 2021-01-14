#include <iostream>
#include <string>
#include <cctype>
#include <vector>

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
    cout << punct_cnt << " punctuation characters in " << str << endl;

    for (auto &c : str){
        c = toupper(c);
    }
}

void q_3_14(){
    vector<int> v;
    int i;
    while (cin >> i){
        v.push_back(i);
    }
}

void q_3_17(){
    vector<string> v;
    string s;
    while (cin >> s){
        v.push_back(s);
    }

    for (auto &str : v){
        for (auto &c : str){
            c = toupper(c);
        }
    }

    for (auto str : v){
        cout << str << endl;
    }
}

void q_3_31(){
    int a[10];
    for (size_t i=0; i != 10; i++){
        a[i] = i;
    }
}

void basic_vector(){
    string s("some string");
    if (s.begin() != s.end()){
        auto it = s.begin();
        *it = toupper(*it);
    }

    for (auto it = s.begin(); it != s.end() && !isspace(*it); it++)
        *it = toupper(*it);
}