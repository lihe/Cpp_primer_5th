#include <iostream>
#include "Sales_item.h"
using namespace std;

int main(){
    Sales_item total, trans;
    cout << "请输入若干条销售记录：" << endl;
    if (cin >> total){
        size_t sum = 1;
        while (cin >> trans){
            if (trans.isbn() == total.isbn()){
                sum++;
            }
            else{
                cout << total.isbn() << "共有" << sum << "条销售记录" << endl;
                total = trans;
                sum = 1;
            }
        }
        cout << total.isbn() << "共有" << sum << "条销售记录" << endl;
    }
    else{
        cout << "没有数据" << endl;
        return -1;
    }
    return 0;
}