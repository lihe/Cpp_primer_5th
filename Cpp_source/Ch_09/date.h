//
// Created by Leslie on 2021/1/24.
//

#ifndef CPP_PRIMER_5TH_DATE_H
#define CPP_PRIMER_5TH_DATE_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class date{
public:
    friend ostream& operator << (ostream&, const date&);

    date() = default;
    explicit date(const string &ds);

    unsigned y() const {return year;}
    unsigned m() const {return month;}
    unsigned d() const {return day;}

private:
    unsigned year, month, day;
};

// 月份全称
const string month_name[] = {"January", "February", "March", "April", "May", "June", "July", "August",
                             "September", "October", "November", "December"};

// 月份简写
const string month_abbr[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug",
                             "Sept", "Oct", "Nov", "Dec"};

// 每月天数
const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline int get_month(const string &ds, int &end_of_month){
    int i, j;
    for (i = 0; i < 12; i++) {
        for (j = 0; j < month_abbr[i].size(); j++) {
            if (ds[j] != month_abbr[i][j]) {     // 不是此月简写
                break;
            }
        }

        if (j == month_abbr[i].size()) {      // 与简写匹配
            break;
        }
    }

    if (i == 12){        // 与所有月份简写都不匹配
        throw invalid_argument("不合法的月份名！");
    }

    if (ds[j] == ' '){        // 仅仅是月份简写，不是全称
        end_of_month = j + 1;
        return i + 1;
    }

    for (; j < month_name[i].size(); j++){
        if (ds[j] != month_name[i][j])
            break;
    }

    if (j == month_name[i].size() && ds[j] == ' '){       // 是月份全称
        end_of_month = j + 1;
        return i + 1;
    }
    throw invalid_argument("不合法的月份名！");
}

inline int get_day(const string &ds, unsigned month, int &p){      // 从p开始转换为日期值
    size_t q;
    int day = stoi(ds.substr(p), &q);
    if (day < 1 || day > days[month])
        throw invalid_argument("不是合法的日期值！");
    p += q;      // 转移到日期值之后
    return day;
}

inline int get_year(const string &ds, int &p){     // 从p开始转换为年
    size_t q;
    int year = stoi(ds.substr(p), &q);
    if (p + q < ds.size())
        throw invalid_argument("非法结尾内容！");
    return year;
}

date::date(const string &ds){
    int p;
    size_t q;

    if ((p = ds.find_first_of("0123456789")) == string::npos){
        throw invalid_argument("没有数字，不是合法日期！");
    }

    if (p > 0){       // 月份为名称格式
        month = get_month(ds, p);
        day = get_day(ds, month, p);
        if (ds[p] != ' ' && ds[p] != ','){
            throw invalid_argument("非法间隔符！");
        }
        p++;
        year = get_year(ds, p);
    }
    else{        // 月份为数字格式
        month = stoi(ds, &q);
        p = q;
        if (month > 12 || month < 1){
            throw invalid_argument("不是合法的月份！");
        }
        if (ds[p++] != '/'){
            throw invalid_argument("非法间隔符");
        }
        day = get_day(ds, month, p);
        if (ds[p++] != '/'){
            throw invalid_argument("非法间隔符");
        }
        year = get_year(ds, p);
    }
}

ostream & operator << (ostream& out, const date &d){
    out << d.y() << "年" << d.m() << "月" << d.d() << "日" << endl;
    return out;
}
#endif //CPP_PRIMER_5TH_DATE_H
