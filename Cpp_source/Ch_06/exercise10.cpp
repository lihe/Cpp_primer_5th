#include <iostream>
using namespace std;

void swap(int *A, int *B){
    int *temp = A;
    B = A;
    B = temp;
}

int main(){
    int a = 1, b = 2;
    swap(a, b);
    cout << a << endl << b << endl;
    return 0;
}