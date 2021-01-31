//
// Created by Leslie on 2021/1/31.
//

#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include <map>

using namespace std;

void add_family(map<string, vector<string>> &families, const string &family){
    if (families.find(family) == families.end()){
        families[family] = vector<string>();
    }
}

void add_child(map<string, vector<string>> &families, const string &family, const string &child){
    families[family].push_back(child);
}

int main(int argc, char *argv[]){
    map<string, vector<string>> families;
    add_family(families, "zhang");
    add_child(families, "zhang", "qiang");
    add_child(families, "zhang", "dong");
    add_child(families, "zhang", "hao");
    add_family(families, "wang");

    for (const auto &f : families){
        cout << f.first << "'s children: ";
        for (const auto &c : f.second){
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}