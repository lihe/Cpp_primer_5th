//
// Created by Leslie on 2021/1/24.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){
    vector<char> vc{'H', 'e', 'l', 'l', 'o'};

    string c(vc.data(), vc.size());

    cout << c << endl;
    return 0;
}
