#include <iostream>
using namespace std;

class Sale_data{
    friend std:: istream &read(std::istream &, Sale_data &);
    friend std:: ostream &print(std::ostream &, const Sale_data &);

private:
    string bookNo;                   // 书籍编号，隐式初始化S串为空
    unsigned units_sold = 0;         // 销售量
    double sellingprice = 0.0;       // 原始价格
    double saleprice = 0.0;          // 销售价格
    double discount = 0.0;           // 折扣
    double revenue = 0.0;            // 利润

public:
    // 委托构造函数
    Sale_data(const string &book, unsigned num, double sellp, double salep) :
            bookNo(book), units_sold(num), sellingprice(sellp), saleprice(salep){
        if (sellingprice){
            discount = saleprice / sellingprice;
        }
        cout << "该构造函数接受书号、销售量、原价、实际售价四个信息。" << endl;
    }

    Sale_data() : Sale_data("", 0, 0, 0){
        cout << "该构造函数无须接受任何信息。" << endl;
    }

    Sale_data(const string &book) : Sale_data(book, 0, 0, 0) {
        cout << "该构造函数接受书号信息。" << endl;
    }

    Sale_data(std::istream &is) : Sale_data(){
        read(is, *this);
        cout << "该构造函数接受用户输入信息。" << endl;
    }
};

std::istream &read(std::istream &is, Sale_data &item){
    is >> item.bookNo >> item.units_sold >> item.sellingprice >> item.saleprice;
    return is;
}

std::ostream &print(std::ostream &os, const Sale_data &item){
    os << item.bookNo << " " << item.units_sold << " " << item.sellingprice << " " << item.saleprice << " " << item.saleprice;
    return os;
}

int main(int argc, char *argv[]){
    Sale_data first("978-7-121-15535-2", 85, 128, 109);
    Sale_data second;
    Sale_data third("978-7-121-15535-2");
    Sale_data last(cin);
    return 0;
}