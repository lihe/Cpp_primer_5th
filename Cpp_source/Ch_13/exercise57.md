与上一题不同，本题的写法可以正确利用右值引用版本来完成排序。原因在于，编译器认为 Foo（*this）是一个"无主"的右值，对它调用 sorted会匹配右值引用版本。
