#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int A = 1, B = 2;
    swap(A, B);
    cout << A << endl << B << endl;
    return 0;
}