#include "my_StrBlob.h"

using namespace std;

int main(int argc, char *argv[]){
    const StrBlob b = {"hello", "world", "！"};
    for (auto it = b.begin(); neq(it, b.end()); it.incr()){
        cout << it.deref() << endl;
    }
    return 0;
}
