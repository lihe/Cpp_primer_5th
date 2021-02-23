#include <iostream>
#include <string>

using namespace std;

class HasPtr {
public:
    explicit HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &p) : ps(new string(*p.ps)), i(p.i) {}
    HasPtr& operator=(const HasPtr&);
    HasPtr& operator=(const string&);
    string& operator*();
    ~HasPtr();
private:
    string *ps;
    int i;
};

HasPtr::~HasPtr() {
    delete ps;
}

inline
HasPtr& HasPtr::operator=(const HasPtr &rhs) {
    auto newps = new string(*rhs.ps);  // 拷贝指针指向的对象
    delete ps;                         // 销毁原string
    ps = newps;                        // 指向新string
    i = rhs.i;                         // 使用内置的int赋值
    return *this;                      // 返回一个此对象的引用
}

HasPtr& HasPtr::operator=(const string &rhs) {
    *ps = rhs;
    return *this;
}

string& HasPtr::operator*() {
    return *ps;
}

int main(int argc, char *argv[]){
    HasPtr h("hi mom");
    HasPtr h2(h);
    HasPtr h3 = h;
    h2 = "hi dad!";
    h3 = "hi son!";
    cout << "h: " << *h << endl;
    cout << "h2: " << *h2 << endl;
    cout << "h3: " << *h3 << endl;
    return 0;
}
