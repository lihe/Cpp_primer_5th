```c++
class Sales_data {
    friend ostream& operator << (ostream &, const Sales_data &);
    friend istream& operator >> (istream &, const Sales_data &);
    // 其他成员
};

ostream& operator << (ostream &os, const Sales_data &item) {
    const char *sep = ' ';
    os << item.isbn() << sep << item.units_sold << sep << item.revenue << sep << item.avg_price();
    return os;
}

istream& operator >> (istream &in, Sales_data &s){
    in >> s.bookNo >> s.units_sold >> s.sellingprice >> s.sellingprice;
    if (in && s.sellingprice != 0){
        s.discount = s.sellingprice / s.sellingprice;
    }
    else{
        s = Sales_data();   // 输入错误，重置输入数据
    }
    return in;
}
```

