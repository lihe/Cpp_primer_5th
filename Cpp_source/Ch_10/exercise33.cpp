//
// Created by Leslie on 2021/1/28.
//

#include <iostream>
#include <iterator>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
    if (argc != 4){
        cout << "用法：CPP.exe data out1 out2" << endl;
        return -1;
    }

    ifstream in("../" + (string)argv[1]);
    if (!in){
        cout << "打开输入文件失败" << endl;
        return -1;
    }

    ofstream out1("../" + (string)argv[2]);
    if (!out1){
        cout << "打开输出文件1失败" << endl;
        return -1;
    }

    ofstream out2(argv[3]);
    if (!out2){
        cout << "打开输入文件2失败" << endl;
    }

    istream_iterator<int> in_iter(in);
    istream_iterator<int> eof;
    ostream_iterator<int> out_iter1(out1, " ");
    ostream_iterator<int> out_iter2(out2, "\n");
    while (in_iter != eof){
        if (*in_iter & 1){
            *out_iter1++ = *in_iter;
        }
        else{
            *out_iter2++ = *in_iter;
        }
        in_iter++;
    }
    return 0;
}

