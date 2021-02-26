如果采用拷贝并交换方式，执行过程是这样的∶

1. 由于赋值运算符的参数是 Message 类型，因此会将实参拷贝给形参 rhs，这会触发拷贝构造函数，将实参的 contents 和 folders 拷贝给 rhs，并调用 add_to_Folders 将 rhs 添加到 folders 的所有文件夹中。
2. 随后赋值运算符调用 swap 交换*this 和 rhs，首先遍历两者的 folders，将它们从自己的文件夹中删除；然后调用 string 和 set 的 swap 交换它们的 contents和 folders;最后，再遍历两者新的 folders，将它们分别添加到自己的新文件夹中。
3. 最后，赋值运算符结束，rhs 被销毁，析构函数调用 remove_from_Folders将 rhs 从自己的所有文件夹中删除。

显然，语义是正确的，达到了预期目的。但效率低下，rhs 创建、销毁并两次添加、删除是无意义的。而采用拷贝赋值运算符的标准编写方式，形参 rhs 为引用类型，就能避免这些冗余操作，具有更好的性能。

