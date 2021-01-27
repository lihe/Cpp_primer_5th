//
// Created by Leslie on 2021/1/27.
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

void biggies(vector<string> &words, vector<string>::size_type sz){
    elimDups(words);
    for_each(words.begin(), words.end(), [](const string &s) { cout << s << " "; });
    cout << endl;
    // 取一个迭代器，指向最后一个满足size >= sz元素之后的位置
    auto wc = partition(words.begin(), words.end(), [sz](const string &a) { return a.size() >= sz; });
    auto count = wc - words.begin();
    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
    for_each(words.begin(), wc, [](const string &s) { cout << s << " "; });
    cout << endl;
}

int main(int argc, char *argv[]){
    ifstream in("../" + string(argv[1]));
    if (!in){
        cout << "" << endl;
        return -1;
    }
    vector<string> words;
    string word;
    while (in >> word){
        words.push_back(word);
    }
    biggies(words, 4);
    return 0;
}