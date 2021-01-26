//
// Created by Leslie on 2021/1/26.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>


using namespace std;

void output_words(vector<string> &words){
    for (const auto &word : words){
        cout << word << " ";
    }
    cout << endl;
}

bool five_or_more(const string &s1){
    return s1.size() >= 5;
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
    output_words(words);
    auto iter = partition(words.begin(), words.end(), five_or_more);
    output_words(words);
    return 0;
}