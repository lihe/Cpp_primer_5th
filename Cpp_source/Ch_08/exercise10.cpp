//
// Created by Leslie on 2021/1/22.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ifstream in("../data");
    if (!in){
        cerr << "无法打开输入文件！" << endl;
        return -1;
    }
    string line;
    vector<string> words;
    while (getline(in, line)){
        words.push_back(line);
    }
    in.close();
    for (auto s :words){
        istringstream line_str(s);
        string word;
        while (line_str >> word){
            cout << word << " ";
        }
        cout << endl;
    }
    return 0;
}


