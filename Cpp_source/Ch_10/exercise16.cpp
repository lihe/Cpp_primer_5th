//
// Created by Leslie on 2021/1/26.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "make_plural.h"
#include <algorithm>

using namespace std;

void elimDups(vector<string> &words){
    sort(words.begin(), words.end());
    auto end_of_unique = unique(words.begin(), words.end());
    words.erase(end_of_unique, words.end());
}

void biggest(vector<string> &words, vector<string>::size_type sz){
    elimDups(words);     // 将words按照字典排序，删除重复单词
    // 按长度排序，长度相同单词维持字典排序
    stable_sort(words.begin(), words.end(),
                [](const string &a, const string &b) { return a.size() < b.size();} );
    // 获取一个迭代器，指向第一个满足size() >= sz的元素
    auto wc = find_if(words.begin(), words.end(),
                      [sz](const string &a) { return a.size() > sz;} );
    // 计算满足size >= sz的元素的数目
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s")<< " of length "
    << sz << " or longer " << endl;
    // 打印
    for_each(wc, words.end(), [](const string &s) { cout << s << " ";} );
    cout << endl;
}

int main(int argc, char *argv[]){
    ifstream in("../" + string(argv[1]));
    if (!in){
        cout << "打开输入文件失败" << endl;
        return -1;
    }

    vector<string> words;
    string word;

    while (in >> word){
        words.push_back(word);
    }

    biggest(words, 4);

    return 0;
}