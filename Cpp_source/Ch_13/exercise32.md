默认 swap 版本简单交换两个对象的非静态成员，对 HasPtr 而言，就是交换 string指针 ps、引用计数指针use 和整型值i。可以看出，这种语义是符合期望的——两个 HasPtr指向了原来对方的 string，而两者互换 string 后，各自的引用计数本应该是不变的（都是减1再加1）。因此，默认 swap 版本已经能正确处理类指针 HasPtr 的交换，专用 swap 版本不会带来更多收益。

