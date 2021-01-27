//
// Created by Leslie on 2021/1/27.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){
    istream_iterator<int> in_iter(cin);
    istream_iterator<int> eof;
    vector<int> vi;
    while (in_iter != eof){
        vi.push_back(*in_iter++);
    }
    sort(vi.begin(), vi.end());

    ostream_iterator<int> out_iter(cout, " ");
    copy(vi.begin(), vi.end(), out_iter);
    return 0;
}