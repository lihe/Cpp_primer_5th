#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    string currString, preString = "", maxString;
    int curCnt = 1, maxCnt = 0;
    while (cin >> currString){
        if (currString == preString){
            ++curCnt;
            if (curCnt > maxCnt){
                maxCnt = curCnt;
                maxString = currString;
            }
        }
        else{
            curCnt = 1;
        }
        preString = currString;
    }
    if (maxCnt > 1){
        cout << "出现最多的字符串是：" << maxString << "， 出现的次数是：" << maxCnt << endl;
    }
    else{
        cout << "每个字符串都只出现了一次。" << endl;
    }
    return 0;
}