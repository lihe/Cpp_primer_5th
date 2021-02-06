//
// Created by Leslie on 2021/2/5.
//

#ifndef CPP_PERSON_H
#define CPP_PERSON_H
#include <iostream>

using namespace std;

class Person{
    friend std:: istream &read(std::istream &, Person &);
    friend std:: ostream &print(std::ostream &, Person &);
    friend std:: istream operator >> (std::istream &, Person &);

private: 
    string strName;     // 姓名
    string strAddress;  // 地址
public: 
    Person() = default;
    Person(const string &name, const string &address){
        strName = name;
        strAddress = address;
    }
    explicit Person(std::istream &is) { is >> *this; }
    
    string getName() const { return strName; }
    string getAddress() const { return strAddress; }
};

std:: istream &read(std::istream &, Person &);
std:: ostream &print(std::ostream &, Person &);
std:: istream operator >> (std::istream &, Person &);


std::istream &read(std::istream &is, Person &per){
    is >> per.strName >> per.strAddress;
    return is;
}

std::ostream &print(std::ostream &os, Person &per){
    os << per.getName() << per.getAddress();
    return os;
}

std:: istream operator >> (std::istream &is, Person &per){
    is >> per.strName >> per.strName;
}
#endif //CPP_PERSON_H
