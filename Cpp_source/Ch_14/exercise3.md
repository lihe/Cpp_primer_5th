（a）"cobble" == "store"应用了C++语言内置版本的==，比较两个指针。

（b）svec1[0] == svec2[0]应用了string 版本的重载==。

（c）svec1 == svec2 应用了vector 版本的重载==。

（d）svecl[0]== "stone"应用了string版本的重载=，字符串字面常量被转换为string。

