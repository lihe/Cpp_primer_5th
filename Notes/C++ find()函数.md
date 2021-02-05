
string类提供了6个不同的搜索函数，每个函数都有4个重载版本。

下表描述了这些搜索成员函数及其参数。每个搜索操作都返回一个string∶size_type值，表示匹配发生位置的下标。如果搜索失败，则返回一个名为 string∶inpos的static成员。

标准库将npos定义为一个const string∶size_type类型，并初始化为值-1。由于npos 是一个 unsigned类型，此初始值意味着 npos 等于任何 string最大的可能大小。

find函数完成最简单的搜索。它查找参数指定的字符串，若找到，则返回第一个匹配的下标，否则返回npos：

```c++
string name("AnnaBelle");
auto pos1 = name.find("Anna");   //pos1 = 0
```

这段程序返回0，即字符串"Anna"在"AnnaBelle"中第一次出现的下标。

==搜索是大小写敏感的。==

一个更复杂的问题是查找与给定字符串中任何一个字符匹配的位置。例如，下面代码定位name中的第一个数字：

```c++
string numbers("0123456789"), name("r2d2");
// 返回1，即，name中第一个数字的下标
auto pos = name.find_first_of(numbers);
```

如果是要搜索第一个不在参数中的字符，我们应该调用find_first_not_of。例如，为了搜索string中第一个非数字字符。可以这样做：

```c++
string dept("03714p3");
// 返回5
auto pos = dept.find_first_not_of(numbers);
```



| 搜索操作返回指定字符出现的下标，如果未找到返回pos |                                               |
| ------------------------------------------------- | --------------------------------------------- |
| s.find(args)                                      | 查找s中args第一次出现的位置                   |
| s.rfind(args)                                     | 查找s中args最后一次出现的位置                 |
| s.find_first_of(args)                             | 在s中查找args中任何一个字符第一次出现的位置   |
| s.find_last_of(args)                              | 在s中查找args中任何一个字符最后一次出现的位置 |
| s.find_first_not_of(args)                         | 在s中查找第一个不在args中的字符               |
| s.find_last_not_of(args)                          | 在s中查找最后一个不在args中的字符             |



| args必须是下列形式之一 |                                                              |
| ---------------------- | ------------------------------------------------------------ |
| c, pos                 | 从s中位置pos开始查找字符c，pos默认为0                        |
| s2, pos                | 从c中位置pos开始查找字符串s2，pos默认为0                     |
| cp, pos                | 从s中位置pos开始查找指针cp指向的以空字符为结尾的c风格字符串，pos默认为0 |
| cp, pos, n             | 从s中位置pos开始查找指针cp指向的数组的前n个字符              |

## 指定从哪里开始搜索

我们可以传递给 find操作一个可选的开始位置。这个可选的参数指出从哪个位置开始进行搜索。默认情况下，此位置被置为 0。一种常见的程序设计模式是用这个可选参数在字符串中循环地搜索子字符串出现的所有位置：

```c++
string::size_type pos = 0;
//
while ((pos = name.find_first_of(numbers, pos)) != string::npos){
    cout << "found number at index: " << pos <<
        " element is " << name[pos] << endl;
    pos++;
}
```

## 逆向搜索

到现在为止，我们已经用过的 find 操作都是由左至右搜索。标准库还提供了类似的，但由右至左搜索的操作。rfind成员函数搜索最后一个匹配，即子字符串最靠右的出现位置：

```c++
string river("Mississippi");
auto first_pos = river.find("is");   // 返回1
auto last_pos = river.rfind("is");   // 返回4
```
