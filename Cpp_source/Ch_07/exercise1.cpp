#include <iostream>
#include "Sales_data.h"
using namespace std;

int main(){
    Sales_data item1, item2;
    if (read(cin, item1) && read(cin, item1)){
        if (item1.isbn() == item2.isbn()){
            item1.combine(item2);
            print(cout, item1);
            cout << endl;
        }
    }
    else{
        cerr << "Input failed!" << endl;
    }
    return 0;
}