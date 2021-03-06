
#ifndef CPP_PRIMER_5TH_SALES_DATA_H
#define CPP_PRIMER_5TH_SALES_DATA_H

#include <string>
#include <iostream>

using namespace std;

class Sales_data{
    // 友元函数
    friend istream& operator >> (istream&, Sales_data&);
    friend ostream& operator << (ostream&, const Sales_data&);
    friend bool operator == (const Sales_data&, const Sales_data&);
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);

public:
    // 构造函数的三种形式
    Sales_data() = default;
    Sales_data(const string &book) : bookNo(book) { }
    Sales_data(const string &book, const unsigned num, const double sellp, const double salep);
    Sales_data(std::istream &is) { is >> *this; }


    Sales_data& operator += (const Sales_data&);
    string isbn() const {return bookNo;}
    Sales_data &combine(const Sales_data &);
    double avg_price() const;
    
private:
    string bookNo;                   // 书籍编号，隐式初始化S串为空
    unsigned units_sold = 0;         // 销售量
    double sellingprice = 0.0;       // 原始价格
    double saleprice = 0.0;          // 销售价格
    double discount = 0.0;           // 折扣
    double revenue = 0.0;            // 利润
};

// 声明
istream& operator >> (istream&, Sales_data&);
ostream& operator << (ostream&, const Sales_data&);
bool operator == (const Sales_data&, const Sales_data&);
Sales_data add(const Sales_data &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);

Sales_data::Sales_data(const string &book, const unsigned num, const double sellp, const double salep){
    bookNo = book;
    units_sold = num;
    sellingprice = sellp;
    saleprice = salep;
    if (sellingprice != 0){
        discount = saleprice / sellingprice;
    }
}

inline
double Sales_data:: avg_price() const{
    if (units_sold){
        return revenue / units_sold;
    }
    else
        return 0;
}

inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs){
    return lhs.isbn() == rhs.isbn();
}

Sales_data operator + (const Sales_data&, const Sales_data&);

inline bool operator == (const Sales_data &lhs, const Sales_data &rhs){
    return lhs.units_sold == rhs.units_sold && lhs.sellingprice == rhs.sellingprice &&
           lhs.isbn() == rhs.isbn() && lhs.sellingprice == rhs.sellingprice;
}

inline bool operator != (const Sales_data &lhs, const Sales_data &rhs){
    return !(lhs == rhs);
}

Sales_data& Sales_data::combine(const Sales_data &rhs){
    units_sold += rhs.units_sold;
    saleprice = (rhs.saleprice * rhs.units_sold + saleprice * units_sold) / (rhs.units_sold + units_sold);
    if (sellingprice != 0){
        discount = saleprice / sellingprice;
    }
    return *this;
}

Sales_data& Sales_data::operator += (const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    saleprice = (rhs.saleprice * rhs.units_sold + saleprice * units_sold) / (rhs.units_sold + units_sold);
    if (sellingprice != 0)
        discount = saleprice / sellingprice;
    return *this;
}

Sales_data operator + (const Sales_data &lhs, const Sales_data &rhs){
    Sales_data ret(lhs);
    ret += rhs;
    return ret;
}

istream& operator >> (istream& in, Sales_data &s){
    in >> s.bookNo >> s.units_sold >> s.sellingprice >> s.sellingprice;
    if (in && s.sellingprice != 0){
        s.discount = s.sellingprice / s.sellingprice;
    }
    else{
        s = Sales_data();   // 输入错误，重置输入数据
    }
    return in;
}

ostream& operator << (ostream& out, const Sales_data &s){
    out << s.isbn() << " " << s.units_sold << " " << s.sellingprice << " " << s.saleprice << " " << s.discount;
    return out;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs){
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

std::istream &read(std::istream &is, Sales_data &item){
    is >> item.bookNo >> item.units_sold >> item.sellingprice >> item.saleprice;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item){
    os << item.isbn() << " " << item.units_sold << " " << item.sellingprice << " " << item.saleprice << " " << item.discount;
    return os;
}


#endif //CPP_PRIMER_5TH_SALES_DATA_H
