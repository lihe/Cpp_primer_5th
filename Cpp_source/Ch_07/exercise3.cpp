#include <iostream>
#include "Sales_data.h"

using namespace std;

int main(int argc, char *argv[]){
    cout << "请输入交易记录（ISBN、销售量、原价、实际售价）" << endl;
    Sales_data total;
    if (cin >> total) {
        Sales_data trans;
        while (cin >> trans) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            }
            else{
                cout << total << endl;
                total = trans;
            }
        }
        cout << "No data?" << endl;
    }
    else{
        cerr << "No data?" << endl;
        return -1;
    }
    return 0;
}