#include <iostream>

using namespace std;

void swap_pointer(int *&a, int *&b){
    int *temp = a;
    a = b;
    b = temp;
}

int main(){
    int left = 1, right = 2;
    int *A = &left, *B = &right;

    swap_pointer(A, B);
    cout << *A << endl << *B << endl;
    return 0;
}