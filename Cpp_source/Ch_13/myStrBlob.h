//
// Createdby Leslie on 2021/2/24.
//

#ifndef CPP_MYSTRBLOB_H
#define CPP_MYSTRBLOB_H

#include <iostream>
#include <vector>
#include <initializer_list>
#include <memory>
#include <string>
#include <stdexcept>

using namespace std;

class StrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;

public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    explicit StrBlob(vector<string> *p);
    StrBlob(StrBlob &s);
    StrBlob& operator = (StrBlob &rhs);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // 添加和删除元素
    void push_pack(const string &t) { data->push_back(t); }
    void pop_back();
    // 元素访问
    string& front();
    const string& front() const;
    string& back();
    const string& back() const;

    // 提供给StrBlobPtr的接口
    StrBlobPtr begin();
    StrBlobPtr end();

    // const 版本
    StrBlobPtr begin() const;
    StrBlobPtr end() const;

    void push_back(string &&t) { data->push_back(std::move(t)); }

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};

inline StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}
inline StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
inline StrBlob::StrBlob(vector<string> *p) : data(p) {}
inline StrBlob::StrBlob(StrBlob &s) : data(make_shared<vector<string>>(*s.data)) {}

inline StrBlob& StrBlob::operator=(StrBlob &rhs) {
    data = make_shared<vector<string>>(*rhs.data);
    return *this;
}

inline void StrBlob::check(size_type i, const string &msg) const {
    if (i >= data->size())
        throw out_of_range(msg);
}

inline string& StrBlob::front() {
    // 如果vector为空则check会抛出一个异常
    check(0, "front on empty StrBlob");
    return data->front();
}

// const 版本的front
inline const string& StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}

inline string& StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

inline const string& StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}

inline void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

// 当试图访问一个不存在的元素时，StrBlobPtr试图抛出一个异常
class StrBlobPtr {
    friend bool eq(const StrBlobPtr &, const StrBlobPtr &);

public:
    StrBlobPtr() : curr(0) {}
    explicit StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    explicit StrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

    string& deref() const;
    string& deref(int off) const;
    StrBlobPtr& incr();               // 前缀递增
    StrBlobPtr& decr();               // 前缀递减

private:
    shared_ptr<vector<string>> check(size_t, const string &) const;
    weak_ptr<vector<string>> wptr;
    size_t curr; // 在数组中的当前位置
};

inline shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const {
    auto ret = wptr.lock();
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret;     // 返回指向vector的shared_ptr
}

inline string& StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

inline string& StrBlobPtr::deref(int off) const {
    auto p = check(curr + off, "dereference past end");
    return (*p)[curr + off];
}

inline StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    curr++;
    return *this;
}

// 前缀递减
inline StrBlobPtr& StrBlobPtr::decr() {
    // 如果curr为0，递减它就会产生一个非法下标
    --curr;
    check(-1, "decrement past begin of StrBlobPtr");
    return *this;
}

inline StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end() {
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

// const 版本
inline StrBlobPtr StrBlob::begin() const {
    return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end() const {
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

inline bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs){
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    // 若底层vector是同一个
    if (l == r)
        // 则两个指针都是空，或指向相同元素时，它们相等
        return (!r || lhs.curr == rhs.curr);
    else
        return false;
}

inline bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs){
    return !eq(lhs, rhs);
}


#endif //CPP_MYSTRBLOB_H
