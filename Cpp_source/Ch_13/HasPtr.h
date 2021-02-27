//
// Created by Leslie on 2021/2/25.
//

#ifndef CPP_HASPTR_H
#define CPP_HASPTR_H
#include <iostream>
#include <string>

using namespace std;

class HasPtr {
    friend void swap(HasPtr &, HasPtr &);
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &p) : ps(new string(*p.ps)), i(p.i) {}
    HasPtr& operator = (const HasPtr &);
    HasPtr& operator = (HasPtr &&) noexcept;
    HasPtr& operator = (const string &);
    string& operator * () const;
    bool operator < (const HasPtr &) const;
    ~HasPtr() { delete ps; }

private:
    string *ps;
    int i;
};

inline
HasPtr& HasPtr::operator=(HasPtr &&rhs) noexcept {
    cout << "Move Assignment" << endl;
    if (this != &rhs) {
        delete ps;
        ps = rhs.ps;
        rhs.ps = nullptr;
        rhs.i = 0;
    }
    return *this;
}

bool HasPtr::operator<(const HasPtr &rhs) const {
    return *ps < *rhs.ps;
}

inline HasPtr& HasPtr::operator=(const HasPtr &rhs) {
    auto newps = new string(*rhs.ps);
    delete ps;
    ps = newps;
    i = rhs.i;
    return *this;
}

inline string& HasPtr::operator*() const {
    return *ps;
}

inline HasPtr& HasPtr::operator=(const string &rhs) {
    *ps = rhs;
    return *this;
}

inline void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    cout << "交换 " << *lhs.ps << "和" << *rhs.ps << endl;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}


#endif //CPP_HASPTR_H
