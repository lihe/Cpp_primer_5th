//
// Created by Leslie on 2021/1/29.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "Sales_item.h"
#include <list>
#include <fstream>

using namespace std;

inline void output_words(list<string> &words){
    for (const auto &word : words){
        cout << word << " ";
    }
    cout << endl;
}

void elimDups(list<string> &words){
    output_words(words);

    words.sort();
    output_words(words);

    words.unique();
    output_words(words);
}

int main(int argc, char *argv[]){
    ifstream in("../" + (string)argv[1]);
    if (!in){
        cout << "" << endl;
        return -1;
    }

    list<string> words;
    string word;
    while (in >> word){
        words.push_back(word);
    }
    elimDups(words);
    return 0;
}

