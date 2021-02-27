#include <iostream>
#include "String.h"
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    String s1("one"), s2("two");
    cout << s1 << " " << s2 << endl;
    String s3(s2);
    cout << s1 << " " << s2 << " " << s3 << endl;
    s3 = String("three");
    cout << s1 << " " << s2 << " " << s3 << endl;

    vector<String> vs;
    vs.push_back(s1);
    vs.push_back(std::move(s2));
    vs.push_back(String("three"));
    vs.push_back("four");
    for_each(vs.begin(), vs.end(), [](const String &s) { cout << s << " "; });
    cout << endl;
    return 0;
}