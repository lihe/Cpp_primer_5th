这一声明是非法的。因为对于上一题所述的情况，我们需要调用拷贝构造函数，但调用永远也不会成功。因为其自身的参数也是非引用类型，为了调用它，必须拷贝其实参，而为了拷贝实参，又需要调用拷贝构造函数，也就是其自身，从而造成死循环。