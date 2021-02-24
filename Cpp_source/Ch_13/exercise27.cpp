#include <iostream>

using namespace std;

class HasPtr {
public:
    explicit HasPtr(const string &s = string()) : ps(new string(s)), i(0), use(new size_t(1)) {}
    HasPtr(const HasPtr &p) : ps(p.ps), i(p.i), use(p.use) {}
    HasPtr& operator=(const HasPtr &);
    HasPtr& operator=(const string &);
    string& operator*();
    ~HasPtr();
private:
    string *ps;
    int i;
    size_t *use;
};

HasPtr::~HasPtr() {
    if (--*use == 0){
        delete ps;
        delete use;
    }
}

HasPtr& HasPtr::operator=(const HasPtr &rhs) {
    ++*rhs.use;
    if (--*use == 0){
        delete ps;
        delete use;
    }

    ps = rhs.ps;
    use = rhs.use;
    i = rhs.i;
    return *this;
}

HasPtr& HasPtr::operator=(const string &rhs) {
    *ps = rhs;
    return *this;
}

string& HasPtr::operator*() {
    return *ps;
}

int main(int argc, char *argv[]){
    HasPtr h("hi mom！");
    HasPtr h2 = h;   // 未分配新的string，h2和h指向相同的string
    h = "hi dad!";
    cout << "h: " << *h << endl;
    cout << "h2: " << *h2 << endl;
    return 0;
}