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

inline void output_words(vector<string> &words){
    for (const auto &word : words){
        cout << word << " ";
    }
    cout << endl;
}

void biggies(vector<string> &words, vector<string>::size_type sz){
    output_words(words);
    auto count = count_if(words.begin(), words.end(), [=](const string &s){ return s.size() >= sz; });
    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
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