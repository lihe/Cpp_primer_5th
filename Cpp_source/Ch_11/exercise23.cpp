//
// Created by Leslie on 2021/1/31.
//

#include <iostream>
#include <list>
#include <map>
#include <sstream>

using namespace std;

void add_child(multimap<string, string> &families, const string &family, const string &child){
    families.insert({family, child});
}

int main(int argc, char *argv[]){

    multimap<string, string> families;
    add_child(families, "zhang", "qiang");
    add_child(families, "li", "he");
    add_child(families, "zhang", "dong");
    for (const auto &family: families){
        cout << family.first << "家的孩子：" << family.second << endl;
    }
    return 0;
}