//
// Created by Leslie on 2021/1/24.
//

#include <iostream>
#include <string>

using namespace std;

void name_string(string &name, const string &prefix, const string &suffix){
    name.insert(name.begin(), 1, ' ');
    name.insert(name.begin(), prefix.begin(), prefix.end());
    name.append(" ");
    name.append(suffix.begin(), suffix.end());
}

int main(int argc, char *argv[]){
    string s("James Bond");
    name_string(s, "Mr", "II");
    cout << s << endl;

    s = "M";
    name_string(s, "Mrs", "III");
    cout << s << endl;
    return 0;
}
