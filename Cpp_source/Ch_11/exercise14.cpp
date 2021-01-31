//
// Created by Leslie on 2021/1/31.
//

#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

void add_family(map<string, vector<pair<string, string>>> &families, const string &family){
    families[family];
}

void add_child(map<string, vector<pair<string, string>>> &families, const string &family,
               const string &child, const string &birthday){
    families[family].emplace_back(child, birthday);
}

int main(int argc, char *argv[]){
    map<string, vector<pair<string, string>>> families;
    add_family(families, "zhang");
    add_child(families, "zhang", "qiang", "1970-1-1");
    add_child(families, "zhang", "dong", "1999-9-8");
    add_child(families, "zhang", "hao", "1987-9-6");
    add_family(families, "wang");

    for (const auto &f : families){
        cout << f.first << "'s children: ";
        for (const auto &c : f.second){
            cout << c.first << "（生日：" << c.second << ") ";
        }
        cout << endl;
    }

    return 0;
}