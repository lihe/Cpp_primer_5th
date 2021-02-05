

如表 9.10 所示，vector 和 string类型提供了一些成员函数，允许我们与它的实现中内存分配部分互动。capacity 操作告诉我们容器在不扩张内存空间的情况下可以容纳多少个元素。reserve操作允许我们通知容器它应该准备保存多少个元素。

![image-20210125195858989](https://cdn.jsdelivr.net/gh/lihe/Pic/img/20210125195859.png)

只有当需要的内存空间超过当前容量时，reserve 调用才会改变 vector 的容量。如果需求大小大于当前容量，reserve 至少分配与需求一样大的内存空间（可能更大）。

理解 capacity和size 的区别非常重要。容器的size是指它==已经保存==的元素的数目；而 capacity 则是在==不分配新的内存空间的前提下==它最多可以保存多少元素。

下面的代码展示了 size 和 capacity 之间的相互作用∶

```c++
vector<int> ivec;
// size应该为0；capacit的值依赖具体实现
cout << "ivec: size: " << ivec.size() << "capacity: " << ivec.capacity() << endl;
//向ivec添加24个元素
for (vector<int>::size_type ix = 0; ix != 24; ix++)
    ivec.push_back(ix);
//size的值应该为24；capacity应该大于等于24
cout << "ivec: size: " << ivec.size() << "capacity: " << ivec.capacity() << endl;
```

我们知道一个空 vector 的 size 为 0，显然在我们的标准库实现中一个空 vector 的 capacity也为0。

当向 vector中添加元素时，我们知道 size与添加的元素数目相等。而 capacity==至少==与size一样大，具体会分配多少额外空间则视标准库具体实现而定。

在我们的标准库实现中，每次添加1个元素，共添加 24个元素，会使capacity变为32。

可以想象 ivec 的当前状态如下图所示∶

![image-20210125200542702](https://cdn.jsdelivr.net/gh/lihe/Pic/img/20210125200542.png)

现在可以分配一些额外空间：

```c++
ivec.capacity(50);  // 将capacity设置为50，可能会更大

cout << "ivec: size: " << ivec.size() << "capacity: " << ivec.capacity() << endl;
```

我们可以调用shrink_to_fit来要求vector将超出当前大小的多余内存退回给系统：

```c++
ivec.shrink_to_fit();    // 要求归还内存

cout << "ivec: size: " << ivec.size() << "capacity: " << ivec.capacity() << endl;
```

调用shrink_to_fit只是一个请求，标准库并不保证退还内存。