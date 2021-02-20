new有一些灵活性上的局限，其中一方面表现在它将内存分配和对象构造组合在了一起。类似的，delete将对象析构和内存释放组合在了一起。我们分配单个对象时，通常希望将内存分配和对象初始化组合在一起。因为在这种情况下，我们几乎肯定知道对象应有什么值。

当分配一大块内存时，我们通常计划在这块内存上按需构造对象。在此情况下，我们希望将内存分配和对象构造分离。这意味着我们可以分配大块内存，但只在真正需要时才真正执行对象创建操作（同时付出一定开销）。
一般情况下，将内存分配和对象构造组合在一起可能会导致不必要的浪费。例如：

```c++
string *const p = new string[n]; // construct n empty strings
string s;
string *q = p; // q points to the first string
while (cin >> s && q != p + n)
 *q++ = s; // assign a new value to *q
const size_t size = q - p; // remember how many strings we read
// use the array
delete[] p; // p points to an array; must remember to use delete[]
```

new表达式分配并初始化了n个 string。

但是，我们可能不需要n个string，少量 string 可能就足够了。这样，我们就可能创建了一些永远也用不到的对象。

而且，对于那些确实要使用的对象，我们也在初始化之后立即赋予了它们新值。每个使用到的元素都被赋值了两次：第一次是在默认初始化时，随后是在赋值时。

更重要的是，那些没有默认构造函数的类就不能动态分配数组了。

## allocator类

标准库 allocator类定义在头文件memory中，它帮助我们==将内存分配和对象构造分离开来==。

它提供一种类型感知的内存分配方法，它分配的内存是原始的、未构造的。在本节中，我们将介绍这些 allocator操作。

类似 vector，allocator 是一个模板。为了定义一个 allocator 对象，我们必须指明这个 allocator 可以分配的对象类型。当一个 allocator 对象分配内存时，它会根据给定的对象类型来确定恰当的内存大小和对齐位置∶

```c++
allocator<string> alloc; // object that can allocate strings
auto const p = alloc.allocate(n); // allocate n unconstructed strings
```

这个allocate调用为n 个string分配了内存。

| 标准库allocator类及其算法 |                                                              |
| ------------------------- | ------------------------------------------------------------ |
| allocator < T > a         | 定义了一个名为a的allocator对象，它可以为类型为T的对象分配内存 |
| a.allocate(n)             | 分配一段原始、未构造的内存，保存n个类型为T的对象             |
| a.deallocate(p, n)        | 释放从T*指针p中地址开始的内存，这块内存保存了保存n个类型为T的对象；p必须是一个先前由allocate返回的指针，且n必须是p创建时所要求的大小。在调用deallocate前，用户必须对每个在这块内存中创建的对象调用destroy |
| a.construct(p, args)      | p必须是一个类型为T*的指针，指向这一块原始内存；args被传递给类型为T的构造函数，用来在p指向的内存中构造一个对象 |
| a.destroy(p)              | p为T*的指针，此算法对p所指向的对象指向析构函数               |

## allocator 分配未构造的内存

allocator分配的内存是未构造的（unconstructed）。

我们按需要在此内存中构造对象。在新标准库中，construct 成员函数接受一个指针和零个或多个额外参数，在给定位置构造一个元素。

额外参数用来初始化构造的对象。

类似make_shared的参数，这些额外参数必须是与构造的对象的类型相匹配的合法的初始化器：

```c++
auto q = p; // q will point to one past the last constructed element
alloc.construct(q++); // *q is the empty string
alloc.construct(q++, 10, 'c'); // *q is cccccccccc
alloc.construct(q++, "hi"); // *q is hi!
```

还未构造对象的情况下就使用原始内存是错误的

```c++
cout << *p << endl; // ok: uses the string output operator
cout << *q << endl; // disaster: q points to unconstructed memory!
```

当我们用完对象后，必须对每个构造的元素调用destroy来销毁它们。函数destroy接受一个指针，对指向的对象执行析构函数：

```c++
while (q != p)
 alloc.destroy(--q); // free the strings we actuallyallocated
```

在循环开始处，q指向最后构造的元素==之后==的位置。我们在调用 destroy 之前对q进行了递减操作。因此，第一次调用 destroy时，q指向最后一个构造的元素。最后一步循环中我们 destroy了第一个构造的元素，随后q将与p相等，循环结束。

一旦元素被销毁后，就可以重新使用这部分内存来保存其他 string，也可以将其归还给系统。释放内存通过调用 deallocate来完成：

```c++
alloc.deallocte(p, n);
```

我们传递给 deallocate 的指针不能为空，它必须指向由allocate分配的内存。而且，传递给 deallocate 的大小参数必须与调用 allocated 分配内存时提供的大小参数具有一样的值。

## 拷贝和填充未初始化内存的算法

标准库还为 allocator类定义了两个伴随算法，可以在未初始化内存中创建对象。表 描述了这些函数，它们都定义在头文件memory 中。

| allocator算法                                                |                                                              |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| 这些函数在给定目的的位置创建元素，而不是由系统分配内存给他们 |                                                              |
| uninitialized_copy(b, e, b2)                                 | 从迭代器b 和 e 指出的输入范围中拷贝元素到迭代器 b2 指定的未构造的原始内存中。b2 指向的内存必须足够大，能容纳输入序列中元素的拷贝 |
| uninitialized_copy_n(b, n, b2)                               | 从迭代器b 指向的元素开始，拷贝n个元素到b2 开始的内存中       |
| uninitialized_fill(b, e, t)                                  | 在迭代器b 和e指定的原始内存范围中创建对象，对象的值均为 t 的拷贝 |
| uninitialized_fill_n(b, n, b2)                               | 从迭代器b 指向的内存地址开始创建 n 个对象。b 必须指向足够大的未构造的原始内存，能够容纳给定数量的对象 |

作为一个例子，假定有一个 int 的vector，希望将其内容拷贝到动态内存中。我们将分配一块比 vector 中元素所占用空间大一倍的动态内存，然后将原vector中的元素拷贝到前一半空间，对后一半空间用一个给定值进行填充：

```c++
// allocate twice as many elements as vi holds
auto p = alloc.allocate(vi.size() * 2);
// construct elements starting at p as copies of elements in vi
auto q = uninitialized_copy(vi.begin(), vi.end(), p);
// initialize the remaining elements to 42
uninitialized_fill_n(q, vi.size(), 42);
```

类似拷贝算法，uninitialized_copy接受三个迭代器参数。前两个表示输入序列，第三个表示这些元素将要拷贝到的目的空间。传递给 uninitialized_copy 的目的位置迭代器必须指向==未构造的内存==。与 copy 不同， uninitialized_copy 在给定目的位置构造元素。

类似 copy，uninitialized_copy 返回（递增后的）目的位置迭代器。因此，一次 uninitialized_copy 调用会返回一个指针，指向最后一个构造的元素==之后==的位置。

在本例中，我们将此指针保存在q中，然后将q传递给 uninitialized_fil1_n。此函数类似 fill_n，接受一个指向目的位置的指针、一个计数和一个值。它会在目的位置指针指向的内存中创建给定数目个对象，用给定值对它们进行初始化。