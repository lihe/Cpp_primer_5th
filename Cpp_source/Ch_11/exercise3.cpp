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

int main(int argc, char *argv[]){
    ifstream in("../" + (string)argv[1]);
    if (!in){
        cout << "打开输入文件失败！" << endl;
        return -1;
    }

    map<string, size_t > word_count;
    string word;
    while (in >> word){
        word_count[word]++;
    }
    for (const auto &w : word_count){
        cout << w.first << "出现了" << w.second << "次" << endl;
    }
    return 0;
}