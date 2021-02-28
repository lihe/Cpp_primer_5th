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

// 本对象为右值，所以可以原址排序
Foo Foo::sorted() &&{
    cout << "右值引用版本" << endl;
    sort(data.begin(), data.end());
    return *this;
}

// 本对象是const或是一个左值，哪种情况我们都不能对其原址排序
Foo Foo::sorted() const &{
    cout << "左值引用版本" << endl;
    Foo ret(*this);               // 拷贝一个副本
    //return ret.sorted();
    return Foo(*this).sorted();
}

#endif //CPP_FOO_H
