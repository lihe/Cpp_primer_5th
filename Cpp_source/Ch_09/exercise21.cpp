//
// Created by Leslie on 2021/1/23.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> svec;
    string word;
    auto iter = svec.begin();

    while (cin >> word){
        svec.insert(iter, word);
    }

    for (const auto &it : svec)
        cout << it << endl;
    return 0;
}