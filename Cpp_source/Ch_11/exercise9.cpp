//
// Created by Leslie on 2021/1/31.
//

#include <iostream>
#include <list>
#include <fstream>
#include <map>
#include <sstream>

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

    map<string, list<int>> word_lineno;
    string line;
    string word;
    int lineno = 0;
    while (getline(in, line)){
        lineno++;
        istringstream l_in(line);
        while (l_in >> word){
            trans(word);
            word_lineno[word].push_back(lineno);
        }
    }

    for (const auto &w : word_lineno){
        cout << w.first << "所在行：";
        for (const auto &n : w.second){
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}