#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> vInt, size_t index){
    size_t sz = vInt.size();
    if (!vInt.empty() && index < sz){
        cout << vInt[index] << endl;
        print(vInt, index + 1);
    }
}

int main(int argc, char *argv[]){
    vector<int> vInt = {1, 3, 5, 7, 9, 2, 4, 6, 8};
    print(vInt, 0);
    return 0;
}
