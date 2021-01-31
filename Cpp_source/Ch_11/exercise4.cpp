//
// Created by Leslie on 2021/1/29.
//

#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
#include <fstream>
#include <map>

using namespace std;

string &trans(string &s){      // 将标点都去掉，将大写转换为小写
    for (auto i = 0; i < s.size(); i++){
        if (s[i] >= 'A' && s[i] <= 'Z'){
            s[i] -= ('A' - 'a');
        }
        else if (s[i] == ',' || s[i] == '.'){
            s.erase(i, 1);
        }
    }
    return s;
}

int main(int argc, char *argv[]){
    ifstream in("../" + (string)argv[1]);
    if (!in){
        cout << "打开输入文件失败！" << endl;
        return -1;
    }

    map<string, size_t > word_count;
    string word;
    while (in >> word){
        word_count[trans(word)]++;
    }
    for (const auto &w : word_count){
        cout << w.first << "出现了" << w.second << "次" << endl;
    }
    return 0;
}