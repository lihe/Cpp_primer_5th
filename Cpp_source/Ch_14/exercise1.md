不同点：

* 重载操作符必须具有至少一个 class 或枚举类型的操作数。
* 重载操作符不保证操作数的求值顺序，例如对&&和||的重载版本不再具有"短路求值"的特性，两个操作数都要进行求值，而且不规定操作数的求值顺序。

相同点：

* 对于优先级和结合性及操作数的数目都不变。
