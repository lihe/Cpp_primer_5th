由于两个类都未定义拷贝赋值运算符，因此编译器为它们定义了合成的拷贝赋值运算符。

与拷贝构造函数的行为类似，赋值一个 StrBlob时，赋值其唯一的成员 data，使用 shared_ptr的拷贝赋值运算符来完成，因此其引用计数增加1。

赋值一个StrBlobPtr时，赋值成员 wptr，用weak_ptr的拷贝赋值运算符进行赋值，引用计数不变，然后赋值 curr，直接进行内存复制。