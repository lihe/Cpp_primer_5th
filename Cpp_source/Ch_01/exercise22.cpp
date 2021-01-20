#include <iostream>
#include "Sales_item.h"
using namespace std;

int main(){
    Sales_item total, trans;
    cout << "请输入几条ISBN相同的销售记录：" << endl;
    if (cin >> total){
        while (cin >> trans){
            if (compareIsbn(total, trans))
                total = total + trans;
            else{
                cout << "ISBN不同" << endl;
                return -1;
            }
            cout << "汇总消息：" << total << endl;
        }
    }
    else{
        cout << "没有数据！！" << endl;
        return -1;
    }
    return 0;
}