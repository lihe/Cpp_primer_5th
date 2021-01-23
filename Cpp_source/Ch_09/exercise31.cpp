//
// Created by Leslie on 2021/1/23.
//

#include <iostream>
#include <list>

using namespace std;

// list和forward_list迭代器不支持加减运算，因为链表中元素并非在内存中连续存储

int main(int argc, char *argv[]){
    list<int> list{0, 1, 2, 3, 4, 5, 6, 7, 8};

    auto curr = list.begin();

    while (curr != list.end()){
        if (*curr & 1){
            curr = list.insert(curr, *curr);
            curr ++;
            curr ++;
        }
        else{
            curr = list.erase(curr);
        }
    }

    for (const auto &iter : list){
        cout << iter << endl;
    }
    return 0;
}
