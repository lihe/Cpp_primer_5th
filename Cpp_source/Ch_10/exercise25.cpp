//
// Created by Leslie on 2021/1/27.
//

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <fstream>
#include <algorithm>
#include "make_plural.h"

using namespace std;
using namespace std::placeholders;

inline void output_words(vector<string> &words){
    for (const auto &word : words){
        cout << word << " ";
    }
    cout << endl;
}

void elimDups(vector<string> &words){
    sort(words.begin(), words.end());
    auto end_of_unique = unique(words.begin(), words.end());
    words.erase(end_of_unique, words.end());
}

bool check_size(const string &s, string::size_type sz){
    return s.size() >= sz;
}

void biggies(vector<string> &words, vector<string>::size_type sz){
    elimDups(words);
    for_each(words.begin(), words.end(), [](const string &s) { cout << s << " "; });
    cout << endl;
    auto wc = partition(words.begin(), words.end(), bind(check_size, _1, sz));
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

    biggies(words, 6);
    return 0;
}

