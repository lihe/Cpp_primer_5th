//
// Created by Leslie on 2021/2/20.
//

#ifndef CPP_QUERYRESULT_H
#define CPP_QUERYRESULT_H
#include <memory>
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include "TextQuery.h"
#include "make_plural.h"

using namespace std;

class QueryResult{
    friend ostream& print(ostream &, const QueryResult &);

public:
    typedef std::vector<std::string>::size_type line_no;
    typedef std::set<line_no>::const_iterator line_it;
    QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f) : sought(s), lines(p), file(f) {}

private:
    string sought;                    // 查询单词
    shared_ptr<set<line_no>> lines;   // 出现行号
    shared_ptr<vector<string>> file;  // 输入文件
};

ostream& print(ostream &, const QueryResult &);
#endif //CPP_QUERYRESULT_H
