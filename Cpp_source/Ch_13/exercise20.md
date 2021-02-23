两个类都未定义拷贝控制成员，因此都是编译器为它们定义合成版本。

当TextQuery销毁时，合成版本会销毁其file 和wm 成员。对 file 成员，会将 shared_ptr的引用计数减1，若变为0，则销毁所管理的动态vector 对象（会调用 vector和string 的析构函数）。

对wm，调用map的析构函数（从而调用 string、shared_ptr 和 set 的析构函数），会正确释放资源。

当 QueryResult销毁时，合成版本会销毁其 sought、lines 和file成员。

类似 TextQuery，string、shared_ptr、set、vector的析构函数可能被调用，因为这些类都有设计良好的拷贝控制成员，会正确释放资源。

当拷贝一个 TextQuery 时，合成版本会拷贝 file 和 wm 成员。对 file， shared_ptr 的引用计数会加1。对 wm，会调用 map 的拷贝构造函数（继而调用 string、shared_ptr和 set的拷贝构造函数），因此会正确进行拷贝操作。

赋值操作类似，只不过会将原来的资源释放掉，例如，原有的file 的引用计数会减1。
QueryResult 的拷贝和赋值类似。

