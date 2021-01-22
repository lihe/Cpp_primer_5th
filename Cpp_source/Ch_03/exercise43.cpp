//
// Created by Leslie on 2021/1/22.
//

#include <iostream>

using namespace std;

// 多维数组就是内容为数组的数组

int main(int argc, char *argv[]){
    int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    cout << "" << endl;
    for (int (&row)[4] : ia) {
        for (int &col : row) {
            cout << col << " ";
        }
        cout << endl;
    }

    for (int (*p)[4] = ia; p != ia + 3; p++){
        for (int (*q) = *p; q != *p + 4; q++){
            cout << *q << " ";
        }
        cout << endl;
    }
    return 0;
}