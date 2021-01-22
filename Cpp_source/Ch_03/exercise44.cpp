//
// Created by Leslie on 2021/1/22.
//

#include <iostream>

using namespace std;

using int_array = int[4];

// 多维数组就是内容为数组的数组

int main(int argc, char *argv[]){
    int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    for (int_array &row : ia) {
        for (int &col : row) {
            cout << col << " ";
        }
        cout << endl;
    }

    for (int_array *p= ia; p != ia + 3; p++){
        for (int (*q) = *p; q != *p + 4; q++){
            cout << *q << " ";
        }
        cout << endl;
    }
    return 0;
}