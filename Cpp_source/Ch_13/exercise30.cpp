#include "HasPtr.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    HasPtr h("hi mom!");
    HasPtr h2(h);
    HasPtr h3 = h;
    h2 = "hi dad!";
    h3 = "hi son!";
    swap(h2, h3);
    cout << "h: " << *h << endl;
    cout << "h2: " << *h2 << endl;
    cout << "h3: " << *h3 << endl;
    return 0;
}