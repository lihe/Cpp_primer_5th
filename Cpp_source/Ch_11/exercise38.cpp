#include <iostream>
#include <iterator>
#include <list>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include <unordered_map>

using namespace std;

int main(int argc, char *argv[]){
    ifstream in("../" + string(argv[1]));
    if (!in){
        throw runtime_error("打开输入文件失败！");
    }
    unordered_map<string, std::size_t> word_count;
    string word;
    while (in >> word){
        ++word_count[word];
    }
    for (const auto &w : word_count)
        cout << w.first << "出现了" << w.second << "次" << endl;
    return 0;
}
