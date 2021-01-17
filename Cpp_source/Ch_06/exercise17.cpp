#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool any_capital(const string &str){
    for (auto s : str){
        if (isupper(s))
            return true;
    }
    return false;
}

void to_lowercase(string &str){
    for (auto &s : str){
        s = tolower(s);
    }
}

int main(){
    string s("Hello World!");
    cout << any_capital(s) << endl;

    to_lowercase(s);
    cout << s << endl;
    return 0;
}