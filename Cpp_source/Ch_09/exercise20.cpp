//
// Created by Leslie on 2021/1/23.
//

#include <iostream>
#include <list>
#include <deque>

using namespace std;

int main() {
    list<int> ilist = {1, 2, 3, 4, 5, 6, 7};
    deque<int> odd_d, even_d;

    for (auto &iter : ilist){
        if (iter & 1){
            odd_d.push_back(iter);
        }
        else
            even_d.push_back(iter);
    }
    cout << "奇数有：" << endl;
    for (auto &iter : odd_d){
        cout << iter << endl;
    }
    cout << "偶数有：" << endl;
    for (auto &iter : even_d){
        cout << iter << endl;
    }
    return 0;
}