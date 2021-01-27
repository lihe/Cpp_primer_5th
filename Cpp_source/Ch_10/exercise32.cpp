//
// Created by Leslie on 2021/1/27.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "Sales_item.h"
#include <numeric>

using namespace std;

int main(int argc, char *argv[]){
    Sales_item si;
    vector<Sales_item> vs;
    istream_iterator<Sales_item> in_iter(cin);
    istream_iterator<Sales_item> eof;

    while (in_iter != eof){
        vs.push_back(*in_iter++);
    }

    if (vs.empty()){
        cerr << "No data?" << endl;
        return -1;
    }

    sort(vs.begin(), vs.end(), compareIsbn);

    auto l = vs.begin();
    while (l != vs.end()){
        auto item = *l;
        auto r = find_if(l + 1, vs.end(), [item](const Sales_item &item1) { return item1.isbn() != item.isbn(); });
        cout << accumulate(l + 1, r, item) << endl;
        l = r;
    }
    return 0;
}

