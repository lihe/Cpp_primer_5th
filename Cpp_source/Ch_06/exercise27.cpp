#include <iostream>
#include <string>
#include <initializer_list>

using namespace std;

void add(initializer_list<int> list){
    int sum = 0;
    for (auto item : list){
        sum += item;
    }
    cout << sum << endl;
}

int main(){
    auto list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    add(list);
    return 0;
}