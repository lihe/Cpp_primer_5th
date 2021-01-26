//
// Created by Leslie on 2021/1/26.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>

using namespace std;

int main(int argc, char *argv[]){
    ifstream in("../" + string(argv[1]));
    if (!in){
        cout << "打开文件失败" << endl;
        return -1;
    }
    vector<int> vi;
    double val;

    while (in >> val){
        vi.push_back(val);
    }

    cout << "序列中整数之和为：" << accumulate(vi.begin(), vi.end(), 0) << endl;
    return 0;
}