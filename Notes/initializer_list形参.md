

如果函数的实参数量未知但是全部实参的类型都相同，我们可以使用 initializer_list类型的形参。

initializer_list 是一种标准库类型，用于表示某种特定类型的值的数组。initializer_list类型定义在同名的头文件中，它提供的操作如表所示。

| initializer_list提供的操作                |                                                              |
| ----------------------------------------- | ------------------------------------------------------------ |
| initializer_list< T > lst;                | 默认初始化：T类型元素的空列表                                |
| initializer_list< T > lst{a, b, c, d...}; | lst的元素数量和初始值一样多；lst的元素是对应初始值的副本；列表中的元素是const |
| lst2(lst);    lst2 = lst                  | 拷贝或赋值一个initializer_list对象不会拷贝列表中的元素；拷贝后，原始列表和副本共享元素 |
| lst.size()                                | 列表中的数量增量                                             |
| lst.begin()                               | 返回指向lst中首元素的指针                                    |
| lst.end()                                 | 返回指向lst中尾元素下一位置的指针                            |

和 vector 一样，initializer list 也是一种模板类型。

定义 initializer list 对象时，必须说明列表中所含元素的类型

```c++
initializer_list<string> ls;
initializer_list<int> li;
```

和vector不一样的是，initializer_list 对象中的元素永远是==常量值==，我们无法改变 initializer_list 对象中元素的值。

作用于initializer_list对象的begin和end操作类似于vector对应的成员。

begin（）成员提供一个指向列表首元素的指针，end（）成员提供一个指向列表尾后元素的指针。

```c++
void error_msg(initializer_list<string> il){
    for (auto beg = il.begin(); beg != il.end(); beg++)
        cout << *beg << " ";
    cout << endl;
}
```

如果想向 initializer_list形参中传递一个值的序列，则必须把序列放在一对花括号内。

```c++
// expect和actual是string对象
if (expect != actual){
    error_msg({"functionx", expect, actual});
}
else{
    error_msg({"functionx", "okay"});
}
```
