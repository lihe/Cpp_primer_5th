//
// Created by Leslie on 2021/1/27.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Sales_data.h"
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]){
    ifstream in("../" + string(argv[1]));
    if (!in){
        cout << "" << endl;
        return -1;
    }

    vector<Sales_data> sds;
    Sales_data sd;
    while (read(in, sd)){
        sds.push_back(sd);
    }

    sort(sds.begin(), sds.end(), [] (const Sales_data &lhs, const Sales_data &rhs)
    { return lhs.isbn() < rhs.isbn(); });

    for (const auto &s : sds){
        print(cout, s);
        cout << endl;
    }

    return 0;
}