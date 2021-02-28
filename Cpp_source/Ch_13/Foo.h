//
// Created by Leslie on 2021/2/28.
//

#ifndef CPP_FOO_H
#define CPP_FOO_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Foo {
public:
    Foo sorted() &&;
    Foo sorted() const &;

private:
    vector<int> data;
};

Foo Foo::sorted() &&{
    cout << "右值引用版本" << endl;
    sort(data.begin(), data.end());
    return *this;
}

Foo Foo::sorted() const &{
    cout << "左值引用版本" << endl;
    Foo ret(*this);
    //return ret.sorted();
    return Foo(*this).sorted();
}

#endif //CPP_FOO_H
