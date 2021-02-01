#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    string finalGrade;
    int grade;
    cout << "请输入您要检查的成绩：" << endl;

    while (cin >> grade && grade >= 0 && grade <= 100){
        finalGrade = (grade > 90) ? "high pass" : (grade > 75) ? "pass" : (grade > 60) ? "low pass" : "fail";
        cout << "该成绩所处的档次是：" << finalGrade << endl;
        cout << "请输入您要检查的成绩：" << endl;
    }
    return 0;
}