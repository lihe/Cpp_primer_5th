//
// Created by Leslie on 2021/1/23.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){
    vector<int> vi;

    int s, c;

    for (s = vi.size(), c = vi.capacity(); s <= c; s++)
        vi.push_back(1);

    cout << "空间：" << vi.capacity() << "元素数：" << vi.size() << endl;

    for (s = vi.size(), c = vi.capacity(); s <= c; s++)
        vi.push_back(1);

    cout << "空间：" << vi.capacity() << "元素数：" << vi.size() << endl;


    for (s = vi.size(), c = vi.capacity(); s <= c; s++)
        vi.push_back(1);

    cout << "空间：" << vi.capacity() << "元素数：" << vi.size() << endl;


    for (s = vi.size(), c = vi.capacity(); s <= c; s++)
        vi.push_back(1);

    cout << "空间：" << vi.capacity() << "元素数：" << vi.size() << endl;


    for (s = vi.size(), c = vi.capacity(); s <= c; s++)
        vi.push_back(1);

    cout << "空间：" << vi.capacity() << "元素数：" << vi.size() << endl;

    return 0;
}

