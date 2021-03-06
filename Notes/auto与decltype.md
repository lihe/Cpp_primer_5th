## auto类型说明符

编程时常常需要把表达式的值赋给变量，这就要求在声明变量的时候清楚地知道表达式的类型。然而要做到这一点并非那么容易，有时甚至根本做不到。为了解决这个问题， C++11 新标准引入了auto类型说明符，用它就能让编译器替我们去分析表达式所属的类型。

和原来那些只对应一种特定类型的说明符（比如 double）不同，auto让编译器通过初始值来推算变量的类型。显然，auto 定义的变量必须有初始值∶

```c++
//由val1和val2相加的结果可以推断出item的类型
auto item = val1 + val2; // item初始化为val1和val2相加的结果
```

使用 auto也能在一条语句中声明多个变量。因为一条声明语句只能有一个基本数据类型，所以该语句中所有变量的初始基本数据类型都必须一样：

```c++
auto i = 0, *p = &i;       // 正确：i是整数，p是整型指针
auto sz = 0, pi = 3.14;    // 错误：sz和pi的类型不一样
```

### 符合类型、常量和auto

编译器推断出来的auto类型有时候和初始值的类型并不完全一样，编译器会适当地改变结果类型使其更符合初始化规则。

首先，正如我们所熟知的，使用引用其实是使用引用的对象，特别是当引用被用作初始值时，真正参与初始化的其实是引用对象的值。此时编译器以引用对象的类型作为 auto的类型∶

```c++
int i = 0, &r = i;
auto a = r;
```

其次auto一般会忽略掉顶层const，但是底层const一般会保留，比如初始值是一个指向常量的指针时：

```C++
const int ci = i, &cr = ci;
auto b = ci;    // b是一个整数（ci的顶层const特性被忽略掉了）
auto c = ci;    // c是一个整数（cr时ci的别名，ci本身是一个顶层const）
auto d = &i;    // d是一个整型指针
auto e = &ci;   // e是一个指向整数常量的指针（对常量对象取地址是一种底层const）
```

如果希望推断出的auto类型是一个顶层const，需要明确指出：

```c++
const auto f = ci;  // ci的推演类型是int，f是const int
```

还可以将引用的的类型设置为auto，此时原来的规则依然适用：

```c++
auto &g = ci;          // g是一个整型常量的引用，绑定到ci
auto &h = 42;          // 错误：不能为非常量引用绑定字面值
const auto &j = 42;    // 正确：可以为常量引用绑定字面值
```

设置一个类型为auto的引用时，初始值中的顶层常量属性仍然保留。和往常一样，如果我们给初始值绑定一个引用，则此时的常量就不是顶层常量了。

要在一条语句中定义多个变量，切记，符号&和*只从属于某个声明符，而非基本数据类型的一部分，因此初始值必须是同一种类型∶

```c++
auto k = ci, &l = i;
auto &m = ci, *p = &ci;
// 错误：i的类型是int而&ci的类型是const int
auto &n = i, *p2 = &ci;
```

## decltype类型指示符

有时会遇到这种情况：希望从表达式的类型推断出需要定义的变量类型，但是不想用该表达式的值初始化变量。

为了满足这一需求，C++11引入了类型说明符decltype，它的作用是选择并返回操作数的数据类型。

```c++
decltype(f()) sum = x;  // sum的类型就是函数f的返回类型
```

编译器处理顶层 const和引用的方式与auto有些许不同。如果decltype使用的表达式是一个变量，则decltype返回该变量的类型（包括顶层const和引用在内）

```c++
const int ci = 0, &cj = ci;
decltype(ci) x = 0;          // x的类型是const int
decltype(cj) y = x; 		 // y的类型是const int&，y绑定到变量x
decltype(cj) z;				 // 错误：z是一个引用，必须初始化
```

需要指出的是，引用从来都作为其所指对象的同义词出现，只有用在 decltype 处是一个例外。

### decltype和引用

如果 decltype 使用的表达式不是一个变量，则 decltype 返回表达式结果对应的类型。有些表达式将向 decltype 返回一个引用类型。

一般来说当这种情况发生时，意味着该表达式的结果对象能作为一条赋值语句的左值∶

```c++
// decltype的结果可以是引用类型
int i = 42, *p = &i, &r = i;
decltype(r + 0) b;  // 正确：加法的结果是int，因此b是一个未经初始化的int
decltype(*p) c;     // 错误：c是int&，必须初始化
```

因为r是一个引用，因此 decltype（r）的结果是引用类型。

如果想让结果类型是r所指的类型，可以把r作为表达式的一部分，如 r+0，显然这个表达式的结果将是一个具体值而非一个引用。

另一方面，如果表达式的内容是解引用操作，则 decltype 将得到引用类型。

正如我们所熟悉的那样，解引用指针可以得到指针所指的对象，而且还能给这个对象赋值。

因此，decltype（*p）的结果类型就是 int&，而非 int。

decltype和 auto的另一处重要区别是，decltype的结果类型与表达式形式密切相关。

有一种情况需要特别注意∶对于 decltype 所用的表达式来说，如果变量名加上了一对括号，则得到的类型与不加括号时会有不同。

如果 decltype 使用的是一个不加括号的变量，则得到的结果就是该变量的类型；

如果给变量加上了一层或多层括号，编译器就会把它当成是一个表达式。

变量是一种可以作为赋值语句左值的特殊表达式，所以这样的 decltype 就会得到引用类型∶

```c++
// decltype的表达式如果是加上了括号的变量，结果将是引用
decltype((i)) d;    // 错误：d是int&，必须初始化
decltype(i) e;      // 正确：e是一个int
```

`decltype((variable))的结果永远是引用。`

## auto和decltype的区别

* 第一，auto类型说明符用编译器计算变量的初始值来推断其类型，而decltype虽然也让编译器分析表达式并得到它的类型，但是不实际计算表达式的值。
* 第二，编译器推断出来的 auto类型有时候和初始值的类型并不完全一样，编译器会适当地改变结果类型使其更符合初始化规则。例如，auto一般会忽略掉顶层 const，而把底层const保留下来。与之相反，decltype会保留变量的顶层const。
* 第三，与auto不同，decltype 的结果类型与表达式形式密切相关，如果变量名加上了一对括号，则得到的类型与不加括号时会有不同。如果 decltype 使用的是一个不加括号的变量，则得到的结果就是该变量的类型；如果给变量加上了一层或多层括号，则编译器将推断得到引用类型。