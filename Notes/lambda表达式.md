

根据算法接受一元谓词还是二元谓词，我们传递给算法的谓词必须严格接受一个或两个参数。但是，有时我们希望进行的操作需要更多参数，超出了算法对谓词的限制。

如果在编写划分序列的谓词时，可以不必为每个可能的大小都编写一个独立的谓词，显然更有实际价值。

一个相关的例子是，求大于等于一个给定长度的单词有多少。我们还会修改输出，使程序只打印大于等于给定长度的单词。我们将此函数命名为biggies，其框架如下：

```c++
void biggest(vector<string> &words, vector<string>::size_type sz){
    elimDups(words);   // 将words按照字典序排列，删除重复单词
    // 按长度排序，长度相同的维持字典序
    stable_sort(words.begin(), words.end(), isShorter);
    // 获取一个迭代器，指向第一个满足size() >= sz的元素
    // 计算满足size >= sz的元素的数目
    // 打印长度大于等于给定值的单词
}
```

我们的新问题是在 vector 中寻找第一个大于等于给定长度的元素。一旦找到了这个元素，根据其位置，就可以计算出有多少元素的长度大于等于给定值。

我们可以使用标准库 find_if 算法来查找第一个具有特定大小的元素。类似 find，find_if 算法接受一对迭代器，表示一个范围。但与find不同的是，find_if 的第三个参数是一个谓词。find_if 算法对输入序列中的每个元素调用给定的这个谓词。它返回==第一个使谓词返回非0值的元素==，如果不存在这样的元素，则返回尾迭代器。

编写一个函数，令其接受一个 string 和一个长度，并返回一个 bool 值表示该 string的长度是否大于给定长度，是一件很容易的事情。

但是，find_if接受一元谓词——我们传递给 find_if 的任何函数都必须严格接受一个参数，以便能用来自输入序列的一个元素调用它。没有任何办法能传递给它第二个参数来表示长度。为了解决此问题，需要使用另外一些语言特性。

## 介绍lambda

我们可以向一个算法传递任何类别的可调用对象（callable object）。对于一个对象或一个表达式，如果可以对其使用调用运算符，则称它为可调用的。

即，如果e是一个可调用的表达式，则我们可以编写代码 e(args)，其中args是一个逗号分隔的一个或多个参数的列表。

一个 lambda 表达式表示一个==可调用的代码单元==。我们可以将其理解为一个未命名的内联函数。与任何函数类似，一个 lambda 具有一个返回类型、一个参数列表和一个函数体。

但与函数不同，lambda可能定义在函数内部。一个lambda 表达式具有如下形式

`[capture list](parameter list) -> return tyne { function body }`

其中，capture list（捕获列表）是一个lambda所在函数中定义的局部变量的列表（通常为空）；

renurn type、parameter list 和function body与任何普通函数一样，分别表示返回类型、参数列表和函数体。但是，与普通函数不同，lambda 必须使用尾置返回来指定返回类型。

我们可以忽略参数列表和返回值类型， 但必须永远包含捕获列表和函数体

```c++
auto f = [] { return 42; };
```

此例中，我们定义了一个可调用对象f，它不接受参数，返回42。

lambda的调用方式与普通的函数的调用方式相同，都是使用调用运算符：

```c++
cout << f() << endl;
```

在 lambda 中忽略括号和参数列表等价于指定一个空参数列表。

在此例中，当调用 f时，参数列表是空的。如果忽略返回类型，lambda根据函数体中的代码推断出返回类型。如果函数体只是一个return 语句，则返回类型从返回的表达式的类型推断而来。否则，返回类型为void。

## 向lambda传递参数

与一个普通函数调用类似，调用一个 lambda 时给定的实参被用来初始化 lambda的形参。

通常，实参和形参的类型必须匹配。但与普通函数不同，lambda不能有默认参数。因此，一个 lambda调用的实参数目永远与形参数目相等。一旦形参初始化完毕，就可以执行函数体了。

作为一个带参数的 lambda 的例子，我们可以编写一个与isShorter 函数完成相同功能的lambda∶

```c++
[](const string &a, const string &b) { return a.size() < b.size(); }
```

空捕获列表表明此 lambda 不使用==它所在函数中的任何局部变量==。

lambda 的参数与 isShorter 的参数类似，是 const string 的引用。lambda 的函数体也与isShorter类似，比较其两个参数的 size（），并根据两者的相对大小返回一个布尔值。

如下所示，可以使用此 lambda 来调用 stable_sort∶

```c++
stable_sort(words.begin(), words.end(),
            [](const string &a, const string &b) { return a.size() < b.size(); });
```

当stable_sort需要比较两个元素时，它就会调用给定的这个lambda表达式。

## 使用捕获列表

我们现在已经准备好解决原来的问题了——编写一个可以传递给 find_if 的可调用表达式。

我们希望这个表达式能将输入序列中每个string 的长度与biggies 函数中的 sz参数的值进行比较。

虽然一个 lambda 可以出现在一个函数中，使用其局部变量，但它只能使用那些明确指明的变量。一个 lambda通过将局部变量包含在其捕获列表中来指出将会使用这些变量。捕获列表指引 lambda 在其内部包含访问局部变量所需的信息。

在本例中，我们的 lambda 会捕获 sz，并只有单一的 string 参数。其函数体会将 string 的大小与捕获的 sz 的值进行比较：

```c++
[sz](const string &a){ return a.size() >= sz; };
```

lambda 以一对[ ] 开始，我们可以在其中提供一个以逗号分隔的名字列表，这些名字都是它所在函数中定义的。

由于此 lambda捕获 sz，因此 lambda 的函数体可以使用sz。lambda 不捕获words，因此不能访问此变量。如果我们给 lambda提供一个空捕获列表，则代码会编译错误∶

## 调用find_if

使用此lambda，我们就可以查找第一个长度大于sz的元素：

```c++
// 获取迭代器，指向第一个满足size() >= sz的元素
auto wc = find_if(words.begin(), words.end(), 
                  [sz](const string &a) { return a.size() >= sz;} );
```

这里对 find_if 的调用返回一个迭代器，指向第一个长度不小于给定参数 sz 的元素。如果这样的元素不存在，则返回 words.end（）的一个拷贝。

我们可以使用find_if返回的迭代器来计算从它开始到words的末尾一共有多少个元素

```c++
auto count = words.end() - wc;
```

## for_each算法

问题的最后一部分是打印words 中长度大于等于sz的元素。

为了达到这一目的，我们可以使用 for_each 算法。此算法接受一个可调用对象，并对输入序列中每个元素调用此对象：

```c++
// 打印长度大于等于给定值的单词
for_each (wc, words.end(), [](const string &s) { cout << s << " "; });
cout << endl;
```

此 lambda中的捕获列表为空，但其函数体中还是使用了两个名字：s和cout，前者是它自己的参数。

捕获列表为空，是因为我们只对 lambda所在函数中定义的（非static）变量使用捕获列表。==一个lambda可以直接使用定义在当前函数之外的名字==。在本例中，cout 不是定义在biggies中的局部名字，而是定义在头文件iostream中。因此，只要在biggies出现的作用域中包含了头文件 iostream，我们的lambda就可以使用 cout。

## 完整的biggies

```c++
void biggest(vector<string> &words, vector<string>::size_type sz){
    elimDups(words);     // 将words按照字典排序，删除重复单词
    // 按长度排序，长度相同单词维持字典排序
    stable_sort(words.begin(), words.end(),
                [](const string &a, const string &b) { return a.size() < b.size();} );
    // 获取一个迭代器，指向第一个满足size() >= sz的元素
    auto wc = find_if(words.begin(), words.end(),
                      [sz](const string &a) { return a.size() > sz;} );
    // 计算满足size >= sz的元素的数目
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s")<< " of length " << sz << " or longer " << endl;
    // 打印
    for_each(wc, words.end(), [](const string &s) { cout << s << " ";} );
    cout << endl;
}
```
