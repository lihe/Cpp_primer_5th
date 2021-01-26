//
// Created by Leslie on 2021/1/26.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "Sales_data.h"

using namespace std;

int main(int argc, char *argv[]){
    ifstream in("../" + string(argv[1]));
    if (!in){
        cout << "打开文件失败" << endl;
        return -1;
    }

    vector<Sales_data> sds;
    Sales_data sd;
    while (read(in, sd)){
        sds.push_back(sd);
    }

    sort(sds.begin(), sds.end(), compareIsbn);

    for (const auto &s : sds){
        print(cout, s);
        cout << endl;
    }
    return 0;
}