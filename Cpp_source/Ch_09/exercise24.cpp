//
// Created by Leslie on 2021/1/23.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> iv;

    cout << iv.at(0) << endl;      // 返回下标为0的元素的引用
    cout << iv[0] << endl;
    cout << iv.front() << endl;
    cout << *(iv.begin()) << endl;

    return 0;
}