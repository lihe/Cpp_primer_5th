//
// Created by Leslie on 2021/1/29.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
    if (argc != 4){
        cout << "用法：CPP.exe data" << endl;
        return -1;
    }

    ifstream in("../" + (string)argv[1]);
    if (!in){
        cout << "打开输入文件失败" << endl;
        return -1;
    }

    vector<int> vi;
    int v;
    while (in >> v){
        vi.push_back(v);
    }

    for (auto r_iter = vi.crbegin(); r_iter != vi.crend(); r_iter ++){    // 反向迭代器
        cout << *r_iter << " ";
    }
    cout << endl;
    return 0;
}

