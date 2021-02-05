顶层const作用于对象本身：

```c++
const int ci = 42;       // 不能改变ci，const是顶层的
int i = ci;              // 正确：当拷贝ci时，忽略顶层const
int * const p = &i;      // const是顶层的，不能给p赋值
*p = 0;                  // 正确：通过p改变对象的内容是允许的
```

和其他初始化过程一样，当用实参初始化形参时会忽略掉顶层 const。

换句话说，形参的顶层 const 被忽略掉了。当形参有顶层const时，传给它常量对象或者非常量对象都是可以的∶

```c++
void fcn(const int i){} // fcn能读取i，但不能向i写值
```

调用 fcn 函数时，既可以传入 const int 也可以传入 int。

忽略掉形参的顶层 const可能产生意想不到的结果：

```c++
void fcn(const int i){} // fcn能读取i，但不能向i写值
void fcn(int i){}       // 错误：重新定义了fcn(int)
```

在 C++语言中，允许我们定义若干具有相同名字的函数，不过前提是不同函数的形参列表应该有明显的区别。

因为顶层 const被忽略掉了，所以在上面的代码中传入两个fcn 函数的参数可以完全一样。

因此第二个 fcn 是错误的，尽管形式上有差异，但实际上它的形参和第一个 fcn 的形参没什么不同。

### 指针或引用形参与const

形参的初始化方式和变量的初始化方式是一样的。

我们可以使用非常量初始化一个底层 const 对象，但是反过来不行；同时一个普通的引用必须用同类型的对象初始化。

```c++
int i = 42;
const int *cp = &i;    // 正确：但是cp不能改变i
const int &r = i;      // 正确：但是r不能改变i
const int &r2 = 42;    // 正确
int *p = cp;           // 错误：p和cp的类型不匹配
int &r3 = r;           // 错误：r3和r的类型不匹配
int &r4 = 42;          // 错误：不能用字面值初始化一个非常量引用
```

将同样的初始化规则应用到参数传递上可得如下形式：

```c++
string::size_type find_char(const string &s, char c, string::size_type &occurs);
void reset(int *i);                       // 指针版本
void reset(int &i);                       // 引用版本

int i = 0;
const int ci = i;
string::sizel_type ctr = 0;
reset(&i);                                // 调用形参类型是int*的reset函数
reset(&ci);                               // 错误：不能用指向const int对象的指针初始化int*

reset(i);                                 // 调用形参类型是int&的reset函数
reset(ci);                                // 错误：不能把普通引用绑定到const对象ci上
reset(42);                                // 错误；不能把普通引用绑定到字面值上
reset(ctr);                               // 错误：类型不匹配
// 正确：find_char的第一个形参是对常量的引用
find_char("Hello world!", 'o', ctr);
```

要想调用引用版本的reset，只能使用int类型的对象，而不能使用字面值、求值结果为 int 的表达式、需要转换的对象或者 const int 类型的对象。

类似的，要想调用指针版本的 reset只能使用 int*。

另一方面，我们能传递一个字符串字面值作为find char的第一个实参，这是因为该函数的引用形参是常量引用，而C++允许我们用字面值初始化常量引用。

### 尽量使用常量引用

把函数不会改变的形参定义成（普通的）引用是一种比较常见的错误，这么做带给函数的调用者一种误导，即函数可以修改它的实参的值。

此外，使用引用而非常量引用也会极大地限制函数所能接受的实参类型。就像刚刚看到的，我们不能把 const 对象、字面值或者需要类型转换的对象传递给普通的引用形参。

这种错误绝不像看起来那么简单，它可能造成出人意料的后果。以 find_char 函数为例，函数（正确地）将它的string类型的形参定义成常量引用。假如我们把它定义成普通的 string&∶

```c++
string::size_type find_char(string &s, char c, string::size_type &occurs);
```

则只能将find_char函数作用于string对象。类似以下这样的调用

```c++
find_char("Hello world!", 'o', ctr);
```

将在编译时发生错误。

还有一个更难察觉的问题，假如其他函数（正确地）将它们的形参定义成常量引用，那么第二个版本的find char无法在此类函数中正常使用。举个例子，我们希望在一个判断 string 对象是否是句子的函数中使用 find_char∶s.

```c++
bool is_sentence(const string &s){
    // 如果s的末尾有且只有一个句号，则s是一个句子。
    string::size_type ctr = 0;
    return find_char(s, '.', str) == s.size() - 1 && ctr == 1;
}
```

如果 find_char的第一个形参类型是 string&，那么上面这条调用find_char的语句将在编译时发生错误。

原因在于s是常量引用，但find_char 被（不正确地）定义成只能接受普通引用。

解决该问题的一种思路是修改is_sentence 的形参类型，但是这么做只不过转移了错误而已，结果是 is_sentence 函数的调用者只能接受非常量 string 对象了。

正确的修改思路是改正 find_char 函数的形参。如果实在不能修改find_char，就在 is_sentence 内部定义一个 string类型的变量，令其为s的副本，然后把这个 string 对象传递给 find_char。
