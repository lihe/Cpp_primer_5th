//
// Created by Leslie on 2021/1/26.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

inline void output_words(vector<string> &words){
    for (const auto &word : words){
        cout << word << " ";
    }
    cout << endl;
}

bool isShorter(const string &s1, const string &s2){
    return s1.size() < s2.size();
}

void elimDups(vector<string> &words){
    output_words(words);

    sort(words.begin(), words.end());
    output_words(words);

    auto end_of_unique = unique(words.begin(), words.end());
    output_words(words);

    words.erase(end_of_unique, words.end());
    output_words(words);

    stable_sort(words.begin(), words.end(), isShorter);
    output_words(words);
}

int main(int argc, char *argv[]){
    ifstream in("../" + string(argv[1]));
    if (!in){
        cout << "打开文件失败" << endl;
        return -1;
    }
    vector<string> words;
    string word;
    while (in >> word){
        words.push_back(word);
    }
    elimDups(words);

    return 0;
}