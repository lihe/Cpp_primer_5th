//
// Created by Leslie on 2021/2/6.
//

#ifndef CPP_WINDOW_MGR_H
#define CPP_WINDOW_MGR_H

#include <iostream>
#include "Screen.h"

using namespace std;

class Window_mgr{
public:
    void clear();
};

void Window_mgr::clear() {
    Screen myScreen(10, 20, 'X');
    cout << "清理之前myScreen的内容是：" << endl;
    cout << myScreen.contents << endl;
    myScreen.contents = "";
    cout << "清理之后myScreen的内容是：" << endl;
    cout << myScreen.contents << endl;
}

#endif //CPP_WINDOW_MGR_H
