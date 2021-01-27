//
// Created by Leslie on 2021/1/27.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include "make_plural.h"

using namespace std::placeholders;

inline void output_words(vector<string> &words){
    for (const auto &word : words){
        cout << word << " ";
    }
    cout << endl;
}

bool check_size(const string &s, string::size_type sz){
    return s.size() <= sz;
}

void biggies(vector<string> &words, vector<string>::size_type sz){
    output_words(words);

    auto count = count_if(words.begin(), words.end(), bind(check_size, _1, sz));
    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or shorter" << endl;
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

    biggies(words, 6);
    return 0;
}

