#include <iostream>
#include "Sales_data.h"

using namespace std;

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