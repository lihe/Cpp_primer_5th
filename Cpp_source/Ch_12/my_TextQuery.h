//
// Created by Leslie on 2021/2/20.
//

#ifndef CPP_MY_TEXTQUERY_H
#define CPP_MY_TEXTQUERY_H
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <memory>
#include <set>
#include "my_QueryResult.h"

using namespace std;

class QueryResult;

class TextQuery{
public:
    using line_no = vector<string>::size_type;
    TextQuery(std::ifstream &);
    QueryResult query(const string &) const;
    void display_map();
private:
    StrBlob file;
    map<string, shared_ptr<set<line_no>>> wm;

    static string cleanup_str(const string &);  // 规范文本：删除标点，转换为小写
};
#endif //CPP_MY_TEXTQUERY_H
