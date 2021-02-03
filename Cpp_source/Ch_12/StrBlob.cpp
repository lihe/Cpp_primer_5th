//
// Created by Leslie on 2021/2/3.
//

#include "StrBlob.h"

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)){}

void StrBlob::check(size_type i, const string &msg) const {
    if (i >= data->size()){
        throw out_of_range(msg);
    }
}

string &StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}

string &StrBlob::back(){
    check(0, "back on empty StrBolb");
    return data->back();
}

const string &StrBlob::back() const {
    check(0, "back on my StrBlob");
    return data->back();
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    pop_back();
}