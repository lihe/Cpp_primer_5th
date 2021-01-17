#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void print(int i){
    cout << i << endl;
}

void print(const int *beg, const int *end){
    while (beg != end){
        cout << *beg++ << endl;
    }
}

void print(const int ia[], size_t size){
    for (size_t i = 0; i != size; i++){
        cout << ia[i] << endl;
    }
}

void print(int (&arr)[2]){  // 形参是数组的引用，维度是类型的一部分。
    for (auto elem : arr){
        cout << elem << endl;
    }
}

int main(){
    int i = 0, j[2] = { 0, 1 };

    print(i);
    print(begin(j), end(j));
    print(j, end(j) - begin(j));
    print(j);

    return 0;
}