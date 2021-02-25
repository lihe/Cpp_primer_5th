#include <iostream>
#include <vector>
#include <algorithm>
#include "HasPtr.h"

using namespace std;

int main(int argc, char *argv[]) {
    vector<HasPtr> vh;
    int n = atoi(argv[1]);
    for (int i = 0; i < n; i++){
        vh.push_back(to_string(n - i));
    }

    for (const auto &p : vh)
        cout << *p << " ";

    cout << endl;
    sort(vh.begin(), vh.end());   // 类中重定义了 '<' 号
    for (const auto &p : vh)
        cout << *p << " ";

    return 0;
}