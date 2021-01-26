//
// Created by Leslie on 2021/1/26.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]){
    ifstream in("../" + string(argv[1]));
    if (!in){
        cout << "打开文件失败" << endl;
        return -1;
    }
    vector<double> vi;
    int val;

    while (in >> val){
        vi.push_back(val);
        cout << val << endl;
    }

    fill_n(vi.begin(), vi.size(), 0);

    for (const auto &v : vi){
        cout << v << endl;
    }
    return 0;
}