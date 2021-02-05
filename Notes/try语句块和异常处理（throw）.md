异常处理包括

* throw表达式，异常检测使用throw表达式来表示它遇到了无法处理的问题。我们说throw引发（raise）了异常。
* try语句块，异常处理部分使用了try语句块处理异常。try语句块以关键字try开始，并以一个或多个catch子语句结束。try语句块中抛出的异常通常会被某个catch子语句处理。
* 一套异常类，以用在throw表达式和相关的catch子语句之间传递异常的处理信息。

## throw表达式

程序的异常检测使用部分使用throw表达式引发一个异常。throw表达式包含关键字throw和紧随其后的一个表达式，其中表达式的类型就是抛出的异常类型。

举个简答的例子

```c++
Sales_item item1, item2;
cin >> item2 >> item2;
// 首先检查item1和item2是否表示同一种书籍
if (item1.isbn() == item2.isbn()){
    cout << item1 + item2 << endl;
    return 0;
}
else{
    cerr << "Data must refer to same ISBN" << endl;
    return -1;
}
```

在真实的程序中应该把对象相加的代码和用户交互的代码分离开来。

此例中，我们改写程序使得检查完成后不再直接输出一条信息，而是抛出一个异常：

```c++
if (item1.isbn() != item2.isbn()){
    throw runtime_error("Data must refer to same ISBN");
}
// 如果程序执行到了这里，表示两个ISBN是一样的
cout << item1 + item2 << endl;
```

在这段代码中，如果ISBN号不一样就抛出一个异常，该异常的类型是runtime_error的对象。

抛出异常将终止当前的函数，并把控制权转移给能处理该异常的代码。

## try语句块

在前面的例子中，我们使用了一个throw表达式以避免把两个代表不同书籍的Sales_item相加。

程序本来要执行的任务出现在try语句块中，这是因为这段代码可能会抛出一个runtime_error类型的异常。

```c++
while (cin >> item1 >> item2){
    try{
        // 执行添加两个Sales_item对象的代码
        // 如果添加失败，代码抛出一个runtime_error异常
    }catch (runtime_error err){
        // 提醒用户两个ISBN必须一致
        cout << err.what()
             << "\nTry Again? Enter y or n" << endl;
        char c;
        cin >> c;
        if (!cin || c == 'n')
            break;
    }
}
```

try语句块对应一个catch子语句，该子语句负责处理类型为runtime_error的异常。

如果try语句块的代买抛出了runtime_error异常，接下来执行catch块内的语句。

给用户的提示信息中输出了err.what()的返回值。what是runtime_error的一个成员函数。每个标准库异常都定义了名为what的成员函数，这些函数没有参数，返回值是C风格的字符串。

## 标准异常

![image-20210116151953049](https://cdn.jsdelivr.net/gh/lihe/Pic/img/20210116151953.png)
