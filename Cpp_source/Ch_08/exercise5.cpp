#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main(){
    ifstream in("data");
    if (!in){
        cerr << "" << endl;
        return -1;
    }

    string line;
    vector<string> words;
    while (in >> line){
        words.push_back(line);
    }

    in.close();

    for (auto it : words){
        cout << it << endl;
    }
    return 0;
}