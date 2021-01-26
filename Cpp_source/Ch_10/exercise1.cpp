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
    vector<int> vi;
    int val;
    while (in >> val){
        vi.push_back(val);
    }
    cout << "请输入需要搜索的整数：" << endl;

    cin >> val;

    cout << "序列中包含" << count(vi.begin(), vi.end(), val) << "个" << val;
    return 0;
}