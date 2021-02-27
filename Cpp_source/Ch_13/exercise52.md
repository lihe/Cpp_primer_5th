对hp = hp2，因为 hp2 是一个变量，是一个左值，因此它传递给赋值运算符参数 rhs 的过程是拷贝构造过程，rhs 获得hp2的一个副本，rhs.ps与hp2.ps指向不同的 string，但两个 string包含相同的内容。

在赋值运算符中，交换hp和 rhs，rhs指向 hp原来的 string，在赋值结束后被销毁。最终结果，hp和hp2指向两个独立的 string，但内容相同。

对hp=std::move（hp2），hp2传递给 rhs的过程是移动构造过程，rhs.ps指向 hp2.ps 原来的 string，

hp2 的 ps 被设置为空指针。然后赋值运算符交换 hp 和rhs，rhs指向hp原来的string，在赋值结束后被销毁。最终结果hp指向 hp2 原来的 string，而 hp2 则变为空。