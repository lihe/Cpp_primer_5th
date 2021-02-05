
常量表达式（const expression）是指值==不会改变==并且在==编译过程就能得到计算结果==的表达式。显然，字面值属于常量表达式，用常量表达式初始化的 const 对象也是常量表达式。

一个对象（或表达式）是不是常量表达式由它的数据类型和初始值共同决定，例如：

```c++
const int max_files = 20;         // max_file是常量表达式
const int limit = max_file + 1;   // limit是常量表达式
int staff_size = 27;              // staff_size不是常量表达式
const int sz = get_size()         // sz不是常量表达式
```

尽管 staff_size的初始值是个字面值常量，但由于它的数据类型只是一个普通int 而非 const int，所以它不属于常量表达式。另一方面，尽管 sz 本身是一个常量，但它的具体值直到运行时才能获取到，所以也不是常量表达式。

## constexpr变量

在一个复杂系统中，很难（几乎肯定不能）分辨一个初始值到底是不是常量表达式。当然可以定义一个 const 变量并把它的初始值设为我们认为的某个常量表达式，但在实际使用时，尽管要求如此却常常发现初始值并非常量表达式的情况。可以这么说，在此种情况下，对象的定义和使用根本就是两回事儿。

C++11新标准规定，允许将变量声明为 constexpr 类型以便==由编译器来验证变量的值是否是一个常量表达式==。声明为 constexpr 的变量一定是一个常量，而且必须用常量表达式初始化：

```c++
constexpr int mf = 20;         // 20是常量表达式
constexpr int limit = mf + 1;  // mf + 1是常量表达式
constexpr int sz = size();     // 只有当size是一个constexpr函数时才是正确的
```

尽管不能使用普通函数作为 constexpr 变量的初始值，但是新标准允许定义一种特殊的 constexpr 函数。这种函数应该足够简单以使得==编译时就可以计算其结果==，这样就能用 constexpr 函数去初始化 constexpr变量了。

==一般来说，如果你认定变量是一个常量表达式，那就把它声明成 constexpr类型。==

## 字面值类型

常量表达式的值需要在==编译时==就得到计算，因此对声明 constexpr 时用到的类型必须有所限制。因为这些类型一般比较简单，值也显而易见、容易得到，就把它们称为"字面值类型"（literal type）。

到目前为止接触过的数据类型中，算术类型、引用和指针都属于字面值类型。

自定义类 Sales_item、IO 库、string 类型则不属于字面值类型，也就不能被定义成 constexpr。

尽管指针和引用都能定义成 constexpr，但它们的初始值却受到严格限制。

一个 constexpr指针的初始值必须是nullptr或者0，或者是存储于某个固定地址中的对象。

函数体内定义的变量一般来说并非存放在固定地址中，因此 constexpr指针不能指向这样的变量。

相反的，定义于==所有函数体之外==的对象其地址固定不变，能用来初始化 constexpr指针。允许函数定义一类有效范围超出函数本身的变量，这类变量和定义在函数体之外的变量一样也有固定地址。因此，constexpr 引用能绑定到这样的变量上，constexpr 指针也能指向这样的变量。

## 指针和constexpr

必须明确一点，在 constexpr明中如果定义了一个指针，限定符 constexpr仅对指针有效，与指针所指对象无关：

```c++
const int *p = nullptr;       // p是一个指向整型常量的指针
constexpr int *q = nullptr;   // p是一个指向整数的常量指针
```

p 和q的类型相差甚远，p 是一个指向常量的指针，而q是一个常量指针，其中的关键在于 constexpr 把它所定义的对象置为了顶层 const。

与其他常量指针类似，constexpr 指针既可以指向常量也可以指向一个非常量 

```c++
constexpr int *np = nullptr;  // np是一个指向整数的常量指针，其值为空
int j = 0;
constexpr int i = 42;         // i的类型是整型常量  
//i和j必须定义在函数体之外
constexpr const int *p = &i;  // p是常量指针，指向整型常量i
constexpr int *p1 = &j;       // p1是常量指针，指向整数j
```

