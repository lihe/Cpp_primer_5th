```c++
HasPtr& HasPtr::operator=(const HasPtr &rhs){
    auto newps = new string(*rhs.ps);      // 拷贝指针指向的对象
    delete ps;                             // 销毁原string
    ps = newps;                            // 指向新string
    i = rhs.i;                             // 使用内置的int赋值
    return *this;                          // 返回一个此对象的引用
}
```

