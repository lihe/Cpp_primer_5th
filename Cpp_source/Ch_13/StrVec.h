//
// Created by Leslie on 2021/2/26.
//

#ifndef CPP_STRVEC_H
#define CPP_STRVEC_H

#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include <algorithm>

using namespace std;

class StrVec {
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(initializer_list<string>);
    StrVec(const StrVec&);
    StrVec(StrVec &&) noexcept;
    StrVec& operator=(const StrVec&);
    StrVec& operator=(StrVec &&) noexcept;
    ~StrVec();

    void push_back(const string &);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - first_free; }
    void reserve(size_t n) { if (n > capacity()) reallocate(); }
    string *begin() const { return elements; }
    string *end() const { return first_free; }
    void resize(size_t);
    void resize(size_t, const string &);

private:
    static allocator<string> alloc;                                     // 分配元素
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    pair<string*, string*> alloc_n_copy(const string *, const string *);
    void free();                                                        // 销毁元素并释放内存
    void reallocate();                                                  // 获取更多元素并拷贝已有元素
    string *elements;                                                   // 指向数组首元素的指针
    string *first_free;                                                 // 指向数组第一个空闲元素的指针
    string *cap;                                                        // 指向数组尾后元素的指针
};

inline StrVec::StrVec(StrVec &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap) {
    s.elements = s.first_free = s.cap = nullptr;
}

inline StrVec::StrVec(initializer_list<string> il) {
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

inline StrVec & StrVec::operator=(StrVec &&rhs) noexcept {
    if (this != &rhs) {
        free();     // free existing elements
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}
inline void StrVec::resize(size_t n) {
    if (n > size()) {
        while (size() < n)
            push_back("");
    }
    else if (n < size()) {
        while (size() > n)
            alloc.destroy(--first_free);
    }
}

inline void StrVec::resize(size_t n, const string &s) {
    if (n > size()) {
        while (size() < n)
            push_back(s);
    }
}

inline void StrVec::push_back(const string &s) {
    chk_n_alloc();                          // 确保有空间容纳新元素
    alloc.construct(first_free++, s);
}

inline pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e) {
    auto data = alloc.allocate(e - b);                  // 分配空间保存给定范围中的元素
    return { data, uninitialized_copy(b, e, data) };
}

inline void StrVec::free() {
    if (elements) {
        // for (auto p = first_free; p != elements; alloc.destroy(--p));      // 逆序销毁旧元素
        for_each(elements, first_free, [](string &s) { alloc.destroy(&s); });
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec() {
    free();
}

inline  StrVec& StrVec::operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

inline void StrVec::reallocate() {
    // 分配两倍大小的内存空间
    auto newcapacity = size() ? 2 * size() : 1;
    auto first = alloc.allocate(newcapacity);
    // 移动元素
    auto last =  uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), first);
    free();                            // 释放旧空间
    elements = first;                  // 更新指针  
    first_free = last;
//
//    // 将数据从旧内存移动到新内存
//    auto dest = newdata;               // 指向新数组中下一个空闲位置
//    auto elem = elements;              // 指向旧数组中下一个位置
//
//    for (size_t i = 0; i != size(); i++)
//        alloc.construct(dest++, std::move(*elem++));
//    free();                            // 一旦移动完元素就释放旧内存
//
//    // 更新数据结构
//    elements = newdata;
//    first_free = dest;
    cap = elements + newcapacity;
}


#endif //CPP_STRVEC_H
