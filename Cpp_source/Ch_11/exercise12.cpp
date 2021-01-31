#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]){
    ifstream in("../" + string(argv[1]));
    if (!in){
        cout << "打开输入文件失败！" << endl;
        return -1;
    }
    vector<pair<string, int>> data;
    string s;
    int v;
    while (in >> s && in >> v){
        data.emplace_back(s, v);
        // data.push_back({s, v});
        // data.push_back(make_pair(s, v));
    }
    for (const auto &d : data){
        cout << d.first << " " << d.second << endl;
    }
    return 0;
}