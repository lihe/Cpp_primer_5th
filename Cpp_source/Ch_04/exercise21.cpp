#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]){
    vector<int> vInt;
    const int sz = 10;
    srand((unsigned) time (NULL));  //  生成随机数种子
    cout << "数组的初始值是：" << endl;
    for (int i = 0; i != sz; ++i){
        vInt.push_back(rand() % 100);  // 生成100以内随机数
        cout << vInt[i] << " ";
    }
    cout << endl;

    for (auto &val : vInt){
        val = (val % 2 != 0) ? val * 2 : val;
    }
    cout << "调整后的数组值是：" << endl;
    for (const auto &v : vInt){
        cout << v << " ";
    }
    return 0;
}