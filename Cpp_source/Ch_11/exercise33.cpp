#include <iostream>
#include <list>
#include <fstream>
#include <map>
#include <sstream>

using namespace std;

map<string, string> buildMap(ifstream &map_file) {
    map<string, string> trans_map;
    string key;
    string value;
    while (map_file >> key && getline(map_file, value)){
        if (value.size() > 1){
            trans_map[key] = value.substr(1);  // 跳过空格
        }
        else{
            throw runtime_error("no rules for " + key);
        }
    }
    return trans_map;
}

const string &transform(const string &s, const map<string, string> &m){
    auto map_it = m.find(s);
    if (map_it != m.end()){
        return map_it->second;
    }
    else{
        return s;
    }
}

void word_transform(ifstream &map_file, ifstream &input){
    auto trans_map = buildMap(map_file);
    string next;
    while (getline(input, next)){
        istringstream stream(next);
        string word;
        bool firstword = true;
        while (stream >> word){
            if (firstword){
                firstword = false;
            }
            else
                cout << " ";
            cout << transform(word, trans_map);
        }
    }
}

int main(int argc, char *argv[]){
    if (argc != 3)
        throw runtime_error("wrong number of argument");

    ifstream map_file("../" + string(argv[1]));
    if (!map_file)
        throw runtime_error("no transform file");

    ifstream input("../" + (string)argv[2]);
    if (!input)
        throw runtime_error("no input file");

    word_transform(map_file, input);
    return 0;
}


