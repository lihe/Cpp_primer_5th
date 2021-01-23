//
// Created by Leslie on 2021/1/23.
//

#include <iostream>
#include <forward_list>

using namespace std;

int main() {
    forward_list<int>iflst = {1, 2, 3, 4, 5, 6, 7, 8};

    auto prev = iflst.before_begin();   // 前驱元素
    auto curr = iflst.begin();          // 当前元素

    while (curr != iflst.end()){
        if (*curr & 1){
            curr = iflst.erase_after(prev);
        }
        else{
            prev = curr;
            curr++;
        }
    }

    for (const auto &iter : iflst){
        cout << iter << endl;
    }

    return 0;
}
