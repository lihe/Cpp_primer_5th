#include <iostream>
#include "Sales_item.h"
using namespace std;

int main(){
    Sales_item book;
    cout << "请输入销售记录：" << endl;
    while (cin >> book){
        cout << "ISBN、销售本数、销售额和平均售价位 " << book << endl;
    }
    return 0;
}