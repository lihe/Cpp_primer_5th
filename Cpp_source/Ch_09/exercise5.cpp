//
// Created by Leslie on 2021/1/22.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int>::iterator search_vec(vector<int>::iterator beg, vector<int>::iterator end, int val){
    for (;beg != end; beg++){
        if (*beg == val){
            return beg;
        }
    }
    return end;
}

int main(int argc, char *argv[]){
    vector<int> ilist = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << search_vec(ilist.begin(), ilist.end(), 3) - ilist.begin()<< endl;
    cout << search_vec(ilist.begin(), ilist.end(), 6) - ilist.begin()<< endl;
    return 0;
}