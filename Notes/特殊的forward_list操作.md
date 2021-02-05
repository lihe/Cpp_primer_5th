

当添加或删除一个元素时，删除或添加的元素之前的那个元素的后继会发生改变。为了添加或删除一个元素，我们需要访问其前驱，以便改变前驱的链接。

但是， forward_list 是单向链表。在一个单向链表中，没有简单的方法来获取一个元素的前驱。出于这个原因，在一个 forward_list 中添加或删除元素的操作是通过==改变给定元素之后的元素==来完成的。这样，我们总是可以访问到被添加或删除操作所影响的元素。

由于这些操作与其他容器上的操作的实现方式不同，forward_list 并未定义 insert、emplace和erase，而是定义了名为insert_after、emplace_after和 erase_after 的操作（参见表 9.8）。

例如，在我们的例子中，为了删除 elem3，应该用指向 elem2的迭代器调用 erase_after。为了支持这些操作，forward_list也定义了 before_begin，它返回一个首前（off-the-beginning）迭代器。

这个迭代器允许我们在链表首元素之前并不存在的元素"之后"添加或删除元素（亦即在链表首元素之前添加删除元素）。

![image-20210125164304986](https://cdn.jsdelivr.net/gh/lihe/Pic/img/20210125164305.png)

当在 forward_list 中添加或删除元素时，我们必须关注两个迭代器——一个指向我们要处理的元素，另一个指向其前驱。例如，可以改写第312 页中从list中删除奇数元素的循环程序，将其改为从 forward list 中删除元素：

```c++
forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
auto prev = flst.before_begin();          // 表示flst的首前元素
auto curr = flst.begin();                 // 表示flst的第一个元素
while (curr != flst.end()){               // 仍有元素要处理
    if (*curr % 2)                        // 若元素为奇数
        curr = flst.erase_after(prev);    // 删除它并移动curr
    else{
        prev = curr;
        curr++;                           // 移动迭代器
    }
}
```

此例中，curr表示我们要处理的元素，prev表示 curr的前驱。

调用begin来初始化 curr，这样第一步循环就会检查第一个元素是否是奇数。

我们用before_begin来初始化 prev，它返回指向 curr 之前不存在的元素的迭代器。

当找到奇数元素后，我们将 prev 传递给 erase_after。此调用将 prev之后的元素删除，即，删除 curr指向的元素。

然后我们将curr重置为erase_after的返回值（返回指向最后一个被删元素之后位置的迭代器），使得 curr指向序列中下一个元素，prev保持不变，仍指向（新）curr之前的元素。如果 curr 指向的元素不是奇数，在 else 中我们将两个迭代器都向前移动。
