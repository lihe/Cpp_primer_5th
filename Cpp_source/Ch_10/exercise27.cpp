//
// Created by Leslie on 2021/1/27.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main(int argc, char *argv[]){
    vector<int> vi = {1, 2, 2, 3, 3, 4, 5, 6, 7, 8};
    list<int> li;
    unique_copy(vi.begin(), vi.end(), back_inserter(li));
    for (const auto &v : li){
        cout << v << " ";
    }
    cout << endl;
    return 0;
}