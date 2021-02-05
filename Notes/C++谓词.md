
谓词是一个可调用的表达式，其返回结果是一个能用作条件的值。

标准库算法所使用的谓词分为两类：==一元谓词==（unary predicate，意味着它们只接受单一参数）和==二元谓词==（binary predicate，意味着它们有两个参数）。

接受谓词参数的算法对输入序列中的元素调用谓词。因此，元素类型必须能转换为谓词的参数类型。

接受一个二元谓词参数的 sort 版本用这个谓词代替 < 来比较元素。

此操作必须在输入序列中所有可能的元素值上定义一个一致的序。

```c++
bool isShorter(const string &s1, const string &s2){
    return s1.size() < s2.size();
}
// 按长度由短到长排序words
sort(words.begin(), words.end(), isShorter);
```

isShorter 就是一个满足这些要求的函数，因此可以将 isShorter 传递给 sort。这样做会将元素按大小重新排序：

此调用会将words 重排，使得所有长度为3的单词排在长度为 4的单词之前，然后是长度为 5 的单词，依此类推。
