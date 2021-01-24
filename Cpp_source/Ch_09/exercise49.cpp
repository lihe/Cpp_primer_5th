//
// Created by Leslie on 2021/1/24.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void find_longest_word(ifstream &in){
    string s, longest_word;
    int max_length = 0;

    while (in >> s){
        if (s.find_first_of("bdfghjklpqty") != string::npos){
            continue;
        }
        cout << s << " ";
        if (max_length < s.length()){
            max_length = s.length();
            longest_word = s;
        }
    }
    cout << "最长字符串：" << longest_word << endl;
}

int main(int argc, char *argv[]){
    ifstream in("../"+ string(argv[1]));
    if (!in){
        cout << "无法打开文件" << endl;
        return -1;
    }
    find_longest_word(in);
    return 0;
}