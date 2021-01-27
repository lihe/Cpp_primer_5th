//
// Created by Leslie on 2021/1/27.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){
    ifstream in("../" + string(argv[1]));
    if (!in){
        cout << "" << endl;
        return -1;
    }

    istream_iterator<string> in_iter(in);
    istream_iterator<string> eof;
    vector<string> words;
    while (in_iter != eof){
        words.push_back(*in_iter++);
    }
    for (const auto &word : words){
        cout << word << " ";
    }
    cout << endl;
    return 0;
}