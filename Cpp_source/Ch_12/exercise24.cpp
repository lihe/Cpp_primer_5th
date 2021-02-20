#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    char c;

    char *r = new char[20];
    int l = 0;
    while (cin.get(c)){
        if (isspace(c)){
            break;
        }
        r[l++] = c;
        if (l == 20){
            cout << "达到数组容量上限" << endl;
            break;
        }
    }
    r[l] = 0;
    cout << r << endl;

    delete [] r;
}
