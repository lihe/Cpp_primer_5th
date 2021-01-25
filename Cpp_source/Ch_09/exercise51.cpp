//
// Created by Leslie on 2021/1/24.
//

#include <iostream>
#include <string>
#include "date.h"

using namespace std;

int main(int argc, char *argv[]){
    string dates[] = {"Jan 1,2014", "February 1,2014", "3/1/2014"};
    try{
        for (const auto &ds : dates){
            date d1(ds);
            cout << d1;
        }
    }catch (invalid_argument e){
        cout << e.what() << endl;
    }
    return 0;
}