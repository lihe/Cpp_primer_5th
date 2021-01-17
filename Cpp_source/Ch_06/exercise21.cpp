#include <iostream>

using namespace std;

int find_bigger(int A, int *B){
    return (A > *B) ? A : *B;
}

int main(){
    int a = 1, b = 2;
    cout << find_bigger(a, &b) << endl;
    return 0;
}