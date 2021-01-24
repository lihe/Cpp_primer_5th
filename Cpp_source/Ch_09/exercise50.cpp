//
// Created by Leslie on 2021/1/24.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){
    vector<string> vs{"1234", "+456", "-789"};  // 两个正数，一个负数
    int sum = 0;
    for (const auto &s : vs){
        sum += stoi(s);
    }
    cout << sum << endl;
    return 0;
}