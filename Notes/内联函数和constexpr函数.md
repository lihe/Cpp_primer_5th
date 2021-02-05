## 内联函数

```c++
const string &shorterString(const string &s1, const string &s2){
    return s1.size() <= s2.size() ? s1 : s2;
}
```

我们编写了一个小函数，它的功能是比较两个 string 形参的长度并返回长度较小的string 的引用。把这种规模较小的操作定义成函数有很多好处，主要包括∶

* 阅读和理解 shorterString 函数的调用要比读懂等价的条件表达式容易得多。
* 使用函数可以确保行为的统一，每次相关操作都能保证按照同样的方式进行。
* 如果我们需要修改计算过程，显然修改函数要比先找到等价表达式所有出现的地方再逐一修改更容易。
* 函数可以被其他应用重复利用，省去了程序员重新编写的代价。

然而，使用 shorterString 函数也存在一个潜在的缺点：调用函数一般比求等价表达式的值要慢一些。

在大多数机器上，一次函数调用其实包含着一系列工作：调用前要先保存寄存器，并在返回时恢复；可能需要拷贝实参；程序转向一个新的位置继续执行。

内联函数可避免函数调用的开销

将函数指定为内联函数（inline），通常就是将它在每个调用点上"内联地"展开。假设我们把 shorterString 函数定义成内联函数，则如下调用

```c++
cout << shorterString(s1, s2) << endl;
```

将在编译中展开成类似于下面的形式

```c++
cout << (s1.size() < s2.size() ? s1 : s2) << endl;
```

从而消除了shorterString函数的和运行时开销。

在shorterString函数的返回类型前面家上关键字inline，这样就可以将它声明成内联函数了：

```c++
// 内联版本
inline const string &shorterString(const string &s1, const string &s2){
    return s1.size() < s2.size() ? s1 : s2;
}
```

一般来说，内联机制用于优化规模较小、流程直接、频繁调用的函数。

## constexpr 函数

constexpr函数（constexpr function）是指能用于常量表达式的函数。

定义 constexpr 函数的方法与其他函数类似，不过要遵循几项约定：函数的返回类型及所有形参的类型都得是字面值类型，而且函数体中必须有且只有一条 return 语句∶

```c++
constexpr int new_sz() {return 42;}
constexpr int foo = new_sz();        // 正确：foo是一个常量表达式。
```

我们把 new_sz 定义成无参数的 constexpr 函数。因为编译器能在程序编译时验证 new_sz 函数返回的是常量表达式，所以可以用 new_sz函数初始化constexpr类型的变量 foo。

执行该初始化任务时，编译器把对 constexpr 函数的调用替换成其结果值。为了能在编译过程中随时展开，constexpr 函数被隐式地指定为内联函数。

constexpr 函数体内也可以包含其他语句，只要这些语句在运行时不执行任何操作就行。

例如，constexpr 函数中可以有空语句、类型别名以及using 声明。

我们允许 constexpr 函数的返回值并非一个常量：

```c++
constexpr size_t scale(size_t cnt) {return new_sz() * cnt;}
```

当scale的实参时常量表达式时，它的返回值也是常量表达式，反之不然：

```c++
int arr[scale(42)];     // 正确：scale(42)是常量表达式
int i = 2;              // i不是常量表达式
int a2[scale(i)];       // 错误：scale(i)不是常量表达式
```

如上例所示，当我们给 scale 函数传入一个形如字面值 2 的常量表达式时，它的返回类型也是常量表达式。此时，编译器用相应的结果值替换对 scale 函数的调用。

如果我们用一个非常量表达式调用 scale 函数，比如 int 类型的对象 i，则返回值是一个非常量表达式。当把 scale 函数用在需要常量表达式的上下文中时，由编译器负责检查函数的结果是否符合要求。如果结果恰好不是常量表达式，编译器将发出错误信息。

**把内联函数和 constexpr 函数放在头文件内**

和其他函数不一样，内联函数和constexpr 函数可以在程序中多次定义。

毕竟，编译器要想展开函数仅有函数声明是不够的，还需要函数的定义。不过，对于某个给定的内联函数或者 constexpr 函数来说，它的多个定义必须完全一致。基于这个原因，内联函数和 constexpr 函数通常定义在头文件中。