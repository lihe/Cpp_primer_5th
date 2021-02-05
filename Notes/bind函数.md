对于那种只在一两个地方使用的简单操作，lambda表达式是最有用的。如果我们需要在很多地方使用相同的操作，通常应该定义一个函数，而不是多次编写相同的 lambda 表达式。类似的，如果一个操作需要很多语句才能完成，通常使用函数更好。

如果 lambda 的捕获列表为空，通常可以用函数来代替它。如前面章节所示，既可以用一个 lambda，也可以用函数isShorter来实现将vector中的单词按长度排序。

类似的，对于打印vector内容的 lambda，编写一个函数来替换它也是很容易的事情，这个函数只需接受一个 string 并在标准输出上打印它即可。

但是，对于==捕获局部变量的 lambda==，用函数来替换它就不是那么容易了。例如，我们用在 find_if 调用中的lambda 比较一个string 和一个给定大小。我们可以很容易地编写一个完成同样工作的函数：

```c++
bool check_size(const string &s, string::size_type sz){
    return s.size() >= sz;
}
```

但是，我们不能用这个函数作为 find_if的一个参数。如前文所示，==find_if 接受一个一元谓词==，因此传递给 find_if 的可调用对象必须接受单一参数。biggies 传递给 find_if 的 lambda 使用捕获列表来保存sz。为了用check_size来代替此 lambda，必须解决如何向 sz 形参传递一个参数的问题。

## 标准库bind函数

我们可以解决向 check_size 传递一个长度参数的问题，方法是使用一个新的名为 bind的标准库函数，它定义在头文件 functional中。可以将bind函数看作一个通用的==函数适配器==，它接受一个可调用对象，生成一个新的可调用对象来“适应“原对象的参数列表。

调用 bind 的一般形式为：

`auto newCallable = bind(callable, arg_list)`

其中，newCallable本身是一个可调用对象，arg_list是一个逗号分隔的参数列表，对应给定的callable的参数。

即，当我们调用 newCallable时，newCallable会调用callable，并传递给它 arg_list 中的参数。

arg_list 中的参数可能包含形如 _ n的名字，其中n是一个整数。这些参数是”占位符“，表示newCallable 的参数，它们占据了传递给 newCallable 的参数的”位置”。数值n表示生成的可调用对象中参数的位置：_ 1为 newCallable 的第一个参数，_2 为第二个参数，依此类推。

## 绑定check_size的sz参数

作为一个简单的例子，我们将使用 bind 生成一个调用 check size 的对象，如下所示，它用一个定值作为其大小参数来调用 check_size：

```c++
// check6是一个可以调用的对象，接受一个string类型参数
// 并用此string和值6来调用check_size
auto check6 = bind(check_size, _1, 6);
```

此 bind 调用只有一个占位符，表示check6 只接受单一参数。占位符出现在arg_list 的第一个位置，表示 check6 的此参数对应 check_size 的第一个参数。此参数是一个 const string&。因此，调用check6 必须传递给它一个string类型的参数，check6会将此参数传递给 check_size。

```c++
string s = "hello";
bool b1 = check6(s);   // check6(s)会调用check_size(s, 6);
```

使用bind， 我们可以将原来的基于lambda的find_if调用：

```c++
auto wc = find_if(words.begin(), words.end(), [sz](const string &s));
```

替换为如下形式：

```c++
auto wc = find_if(words.begin(), words.end(), bind(check_size, _1, sz));
```

此 bind 调用生成一个可调用对象，将 check_size 的第二个参数绑定到 sz 的值。当 find_if对words 中的string调用这个对象时，这些对象会调用check_size，将给定的 string 和 sz 传递给它。因此，find_if 可以有效地对输入序列中每个 string调用 check_size，实现 string 的大小与 sz 的比较。

## bind的参数

如前文所述，我们可以用bind修正参数的值。更一般的，可以用bind绑定给定可调用对象中的参数或重新安排其顺序。例如，假定 f 是一个可调用对象，它有5个参数，则下面对bind 的调用：

```c++
// g是一个有两个参数的可调用对象
auto g =  bind(f, a, b, _2, c, _1);
```

生成一个新的可调用对象，它有两个参数，分别用占位符_ 2 和_ 1表示。这个新的可调用对象将它自己的参数作为第三个和第五个参数传递给 f。

f 的第一个、第二个和第四个参数分别被绑定到给定的值 a、b 和 c 上。

传递给 g的参数按位置绑定到占位符。即，第一个参数绑定到_ 1，第二个参数绑定到_2。因此，当我们调用g 时，其第一个参数将被传递给f 作为最后一个参数，第二个参数将被传递给 f 作为第三个参数。实际上，这个 bind 调用会将

```c++
g(-1, -2)
```

映射为

```c++
f(a, b, _2, c, _1);
```

即，对g的调用会调用f，用g的参数代替占位符，再加上绑定的参数a、b和c。例如，调用g（X，Y）会调用

```c++
f(a, b, Y, c, X);
```

## 绑定引用参数

默认情况下，bind 的那些不是占位符的参数==被拷贝到== bind 返回的可调用对象中。但是，与 lambda 类似，有时对有些绑定的参数我们希望以引用方式传递，或是要绑定参数的类型无法拷贝。
例如，为了替换一个引用方式捕获 ostream 的 lambda：

```c++
// os是一个局部对象，引用一个输出流
// c是一个局部对象，类型为char
for_each(words.begin(), words.end(), [&os, c](const string &s) { os << s << c; });
```

可以很容易地编写一个函数，完成相同的工作

```c++
ostream &print(ostream &os, const string &s, char c){
    return os << s << c;
}
```

但是不能用bind来代替对os的捕获：

```c++
// 错误：不能拷贝os
for_each(words.begin(), words.end(), bind(print, os, _1, ' '));
```

原因在于bind函数拷贝其他参数，而我们不能拷贝一个ostream。如果我们希望传递给bind一个对象而又不拷贝它，就必须使用==ref函数==：

```c++
for_each(words.begin(), words.end(), bind(print, ref(os), _1, ' '));
```

函数 ref 返回一个对象，包含给定的引用，此对象是可以拷贝的。标准库中还有一个cref函数，生成一个保存const 引用的类。与bind一样，函数 ref 和 cref 也定义在头文件 functional中。