//
// Created by Leslie on 2021/2/20.
//

#ifndef CPP_TEXTQUERY_H
#define CPP_TEXTQUERY_H
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <memory>
#include <set>
#include "QueryResult.h"

using namespace std;

class QueryResult;

class TextQuery{
public:
    using line_no = vector<string>::size_type;
    TextQuery(std::ifstream &);
    QueryResult query(const string &) const;

private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;
};
#endif //CPP_TEXTQUERY_H
