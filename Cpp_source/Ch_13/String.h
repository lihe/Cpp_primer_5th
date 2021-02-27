//
// Created by Leslie on 2021/2/26.
//

#ifndef CPP_STRING_H
#define CPP_STRING_H

#include <iostream>
#include <algorithm>
#include <cstring>
#include <initializer_list>
#include <memory>

using namespace std;

class String {

    friend String operator + (const String &, const String &);
    friend String add(const String &, const String &);
    friend ostream& operator << (ostream &, const String &);
    friend ostream& print(ostream &, const String &);

public:
    String() : sz(0), p(nullptr) {}
    String(const char *cp) : sz(strlen(cp)), p(a.allocate(sz)) {
        uninitialized_copy(cp, cp + sz, p);
    }
    String(const String &s) : sz(s.sz), p(a.allocate(s.sz)) {
        uninitialized_copy(s.p, s.p + sz, p);
    }

    String(String &&s) noexcept : sz(s.size()), p(s.p) { s.p = 0; s.sz = 0; }

    String(size_t n, char c) : sz(n), p(a.allocate(n)) {
        uninitialized_fill_n(p, sz, c);
    }

    String& operator = (String &&) noexcept;

    String& operator=(const String &);
    String& operator=(const char *);
    String& operator=(char);
    String& operator=(initializer_list<char>);

    const char *begin() { return p; }
    const char *begin() const { return p; }
    const char *end() { return p + sz; }
    const char *end() const { return p + sz; }

    size_t size() const { return sz; }

    void swap(String &s){
        auto temp = p;
        p = s.p;
        s.p = temp;
        auto cnt = sz;
        sz = s.sz;
        s.sz = cnt;
    }

    ~String() noexcept { if(p) a.deallocate(p, sz); }
private:
    size_t sz;
    char *p;
    static allocator<char> a;
};

inline void swap(String &s1, String &s2) {
    s1.swap(s2);
}

allocator<char> String::a;


String& String::operator=(String &&rhs) noexcept {
    // 检查显式自赋值
    if (p)
        a.deallocate(p, sz);
    p = rhs.p;
    sz = rhs.sz;
    rhs.p = 0;
    rhs.sz = 0;
}

String& String::operator=(const String &rhs) {
    auto newp = a.allocate(rhs.size());
    uninitialized_copy(rhs.p, rhs.p + rhs.sz, newp);

    if (p)
        a.deallocate(p, sz);
    p =  newp;
    sz = rhs.sz;

    return *this;
}

String& String::operator=(const char *cp) {
    if (p)
        a.deallocate(p, sz);
    p = a.allocate(sz = strlen(cp));
    uninitialized_copy(cp, cp + sz, p);
    return *this;
}

String& String::operator=(char c) {
    if (p)
        a.deallocate(p, sz);
    p = a.allocate(sz = 1);
    *p = c;
    return *this;
}

String& String::operator=(initializer_list<char> il) {
    if (p)
        a.deallocate(p, sz);
    p = a.allocate(sz = il.size());
    uninitialized_copy(il.begin(), il.end(), p);
    return *this;
}

String add(const String &lhs, const String &rhs) {
    String ret;
    ret.sz = rhs.size() + lhs.size();
    ret.p = String::a.allocate(ret.sz);
    uninitialized_copy(lhs.begin(), lhs.end(), ret.p);
    uninitialized_copy(rhs.begin(), rhs.end(), ret.p + lhs.sz);
    return ret;
}

ostream& print(ostream &os, const String &s) {
    auto p = s.begin();
    while (p != s.end()) {
        os << *p++;
    }
    return os;
}

String make_plural(size_t ctr, const String &word, const String &end) {
    return (ctr != 1) ? add(word, end) : word;
}

ostream& operator << (ostream & os, const String &s) {
    return print(os, s);
}

String operator + (const String &lhs, const String &rhs) {
    return add(lhs, rhs);
}

#endif //CPP_STRING_H
