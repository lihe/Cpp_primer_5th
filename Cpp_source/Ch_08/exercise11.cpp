//
// Created by Leslie on 2021/1/22.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct PersonInfo{
    string name;
    vector<string> phones;
};

int main(){
    string line, word;
    vector<PersonInfo> people;
    istringstream record;

    while (getline(cin, line)){
        PersonInfo info;
        record.clear();                        // 重复使用字符串流时，每次使用都要clear
        record.str(line);                      // 将记录绑定到刚读入的行
        record >> info.name;
        while (record >> word){
            info.phones.push_back(word);
        }
        people.push_back(info);
    }
    return 0;
}


