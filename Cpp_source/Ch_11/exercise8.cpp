//
// Created by Leslie on 2021/1/31.
//

#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
#include <fstream>
#include <vector>
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
    ifstream in("../" + string(argv[1]));
    if (!in){
        cout << "打开输入文件失败！" << endl;
        return -1;
    }

    vector<string> unique_word;
    string word;
    while (in >> word){
        trans(word);
        if (find(unique_word.begin(), unique_word.end(), word) == unique_word.end()){
            unique_word.push_back(word);
        }
    }

    for (const auto &w : unique_word){
        cout << w << endl;
    }
    return 0;
}