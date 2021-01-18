#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){
    string result;
    for (int i = 1; i != argc; i++){
        result += string(argv[i]) + " ";
    }
    cout << argc << endl;
    cout << result << endl;
    return 0;
}