//
// Created by Leslie on 2021/1/23.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){
    vector<int> vi{1, 2, 3, 4, 5, 6, 7};
    auto iter = vi.begin();

    string tmp;
    while (iter != vi.end()){
        if (*iter % 2){
            iter = vi.insert(iter, *iter);
            iter += 2;
        }
        else
            iter ++;
        for (const auto &vii : vi){  // 方便观察
            cout << vii << " ";
        }
        cout << endl;
        cin >> tmp;
    }

    for (const auto &it : vi){
        cout << it << endl;
    }
    return 0;
}
