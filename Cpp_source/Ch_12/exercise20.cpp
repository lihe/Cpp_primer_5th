#include "my_StrBlob.h"
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
    ifstream in("../" + string(argv[1]));
    if (!in){
        cout << "无法打开输入文件！" << endl;
        return -1;
    }

    StrBlob b;
    string s;
    while (getline(in, s)){
        b.push_back(s);
    }

    for (auto it = b.begin(); neq(it, b.end()); it.incr()){
        cout << it.deref() << endl;
    }

    return 0;
}
