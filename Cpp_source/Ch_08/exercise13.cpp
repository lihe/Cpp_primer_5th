//
// Created by Leslie on 2021/1/22.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct PersonInfo{
    string name;
    vector<string> phones;
};

string format(const string &s) { return s; }

bool valid(const string &s){
    return true;
}

int main(int argc, char *argv[]){
    string line, word;
    vector<PersonInfo> people;
    istringstream record;

    if (argc != 2){
        cerr << "请给出文件名！" << endl;
        return -1;
    }

    ifstream in(argv[1]);

    if (!in){
        cerr << "无法打开文件！" << endl;
        return -1;
    }

    while (getline(in, line)){
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while (record >> word){
            info.phones.push_back(word);
        }
        people.push_back(info);
    }

    ostringstream os;
    for (const auto &entry : people){
        ostringstream formatted, badNums;           // 对people中的每一项每个循环步创建对象
        for (const auto &nums : entry.phones){
            if (!valid(nums)){
                badNums << " " << nums;             // 将数的字符串形式存入badNums
            }
            else{
                formatted << " " << format(nums);   // 将格式化的字符串写入formatted
            }
        }
        if (badNums.str().empty()){
            os << entry.name << " " << formatted.str() << endl;
        }
        else{
            cerr << "input error: " << entry.name << "invalid number(s): " << badNums.str() << endl;
        }
        cout << os.str() << endl;
        return 0;
    }
}


