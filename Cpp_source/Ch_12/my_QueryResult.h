//
// Created by Leslie on 2021/2/20.
//

#ifndef CPP_MY_QUERYRESULT_H
#define CPP_MY_QUERYRESULT_H
#include <memory>
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include "make_plural.h"
#include "my_StrBlob.h"

using namespace std;

class QueryResult{
    friend ostream& print(ostream &, const QueryResult &);

public:
    typedef std::vector<std::string>::size_type line_no;
    typedef std::set<line_no>::const_iterator line_it;

    QueryResult(string s, shared_ptr<set<line_no>> p, StrBlob f) : sought(s), lines(p), file(f) {}
    set<line_no>::size_type size() const { return lines->size(); }
    line_it begin() const { return lines->cbegin(); }
    line_it end() const { return lines->cend(); }
    StrBlob get_file() { return file; }
private:
    string sought;                    // 查询单词
    shared_ptr<set<line_no>> lines;   // 出现行号
    StrBlob file;                     // 输入文件
};

ostream& print(ostream &, const QueryResult &);
#endif //CPP_MY_QUERYRESULT_H
