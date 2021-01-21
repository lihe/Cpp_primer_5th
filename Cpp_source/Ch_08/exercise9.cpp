//
// Created by Leslie on 2021/1/21.
//

#include <iostream>
#include <sstream>

using namespace std;

istream & f(istream & in){
    string v;
    while (in >> v, !in.eof()){
        if (in.bad()){
            throw runtime_error("IO流错误");
        }
        if (in.fail()){
            cerr << "数据错误：请重试！" << endl;
            in.clear();
            in.ignore(100, '\n');
            continue;
        }
        cout << v << endl;
    }
    in.clear();
    return in;
}

int main(int argc, char *argv[]){
    ostringstream msg;
    msg << "C++ Primer 第五版" << endl;
    istringstream in(msg.str());
    f(in);
    return 0;
}
