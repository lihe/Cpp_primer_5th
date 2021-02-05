#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> vInt, unsigned index){
    unsigned sz = vInt.size();
    // 在此处输出调试信息
    #ifdef NDEBUG
    cout << "vector的对象的大小是：" << sz << endl;
    #endif
    if (!vInt.empty() && index < sz){
        cout << vInt[index] << endl;
        print(vInt, index + 1);
    }
}

int main(int argc, char *argv[]){
    vector<int> v = {1, 3, 5, 7, 9, 11, 13, 15};
    print(v, 0);
    return 0;
}