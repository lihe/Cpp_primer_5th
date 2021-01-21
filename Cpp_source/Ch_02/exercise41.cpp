#include <iostream>
#include <string>

using namespace std;

class Sales_data{
    // 友元函数
    friend istream& operator >> (istream&, Sales_data&);
    friend ostream& operator << (ostream&, const Sales_data&);
    friend bool operator == (const Sales_data&, const Sales_data&);

public:
    // 构造函数的三种形式
    Sales_data() = default;
    Sales_data(const string &book) : bookNo(book) { }
    Sales_data(istream &is) {is >> *this;}

    Sales_data& operator += (const Sales_data&);
    string isbn() const {return bookNo;}
private:
    string bookNo;                   // 书籍编号，隐式初始化串为空
    unsigned units_sold = 0;         // 销售量
    double sellingprice = 0.0;       // 原始价格
    double saleprice = 0.0;          // 销售价格
    double discount = 0.0;           // 折扣
};

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

int main(){
    Sales_data book;
    cout << "请输入销售记录：" << endl;
    while (cin >> book){
        cout << "ISBN、售出本数、原始价格、销售价格、折扣为：" << book << endl;
    }
    Sales_data trans1, trans2;
    cout << "请输入两条ISBN相同的销售记录：" << endl;
    cin >> trans1 >> trans2;

    if (compareIsbn(trans1, trans2))
        cout << "汇总信息：ISBN、售出本数、原始价格、销售价格、折扣为：" << trans1 + trans2 << endl;
    else
        cout << "两条销售记录的ISBN不同" << endl;
    Sales_data total, trans;
    cout << "请输入几条ISBN相同的销售记录：" << endl;
    if (cin >> total) {
        while (cin >> total) {
            if (compareIsbn(total, trans))
                total = total + trans;
            else {
                cout << "当前书籍ISBN不同" << endl;
                break;
            }
        }
        cout << "汇总信息：ISBN、售出本数、原始价格、销售价格、折扣为：" << total << endl;
    }
    else{
        cout << "没有数据" << endl;
        return -1;
    }

    int num = 1;
    cout << "输入若干条销售记录：" << endl;
    if (cin >> trans1){
        while (cin >> trans2)
            if (compareIsbn(trans1, trans2))
                num++;
            else{
                cout << trans1.isbn() << "共有" << num << "条销售记录" << endl;
                trans1 = trans2;
                num = 1;
            }
        cout << trans1.isbn() << "共有" << num << "条销售记录" << endl;
    }
    else{
        cout << "没有数据" << endl;
        return -1;
    }
    return 0;
}