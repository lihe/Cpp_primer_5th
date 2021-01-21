//
// Created by Leslie on 2021/1/21.
//

//
// Created by Leslie on 2021/1/21.
//

#include <iostream>
#include <fstream>
#include "Sales_data.h"

using namespace std;

int main(int argc, char *argv[]){
    if (argc != 3){
        cerr << "" << endl;
        return -1;
    }
    ifstream in(argv[1]);
    if (!in){
        cerr << "" << endl;
        return -1;
    }
    ofstream out(argv[2], ofstream::app);
    if (!out){
        cerr << "" << endl;
        return -1;
    }
    Sales_data total;
    if (read(in, total)){
        Sales_data trans;
        while (read(in, trans)){
            if (total.isbn() == trans.isbn()){
                total.combine(trans);
            }
            else{
                print(out, total) << endl;
                total = trans;
            }
        }
        print(out, total) << endl;
    }
    else{
        cerr << "没有数据！" << endl;
    }
    return 0;

}