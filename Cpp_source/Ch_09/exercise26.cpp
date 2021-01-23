//
// Created by Leslie on 2021/1/23.
//

#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};

    vector<int> iv;
    list<int> il;

    iv.assign(ia, ia + 11);
    il.assign(ia, ia + 11);

    auto iiv = iv.begin();

    while (iiv != iv.end()){
        if (!(*iiv & 1)){
            iiv = iv.erase(iiv);
        }
        else
            iiv++;
    }

    auto iil = il.begin();

    while (iil != il.end()){
        if (*iil & 1){
            iil = il.erase(iil);
        }
        else
            iil++;
    }
    cout << "删除vector中偶数" << endl;
    for (const auto &iter : iv)
        cout << iter << endl;
    cout << "删除list中奇数" << endl;
    for (const auto &iter : il)
        cout << iter << endl;

    return 0;
}