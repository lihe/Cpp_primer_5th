在拷贝/移动构造函数和拷贝/移动赋值运算符中添加打印语句，运行练习 13.47中的程序，观察输出结果即可。可以看到，vector 操作部分输出了以下内容∶

Copy Constructor One 

Move Constructor Two 

Move Constructor One 

Move Constructor Three 

Move Constructor One

Move Constructor Two 

Move Constructor Four 

One Two Three Four

容易看出，
vs.push_back（s1）触发一次拷贝构造，对应第一行输出。

vs.push_back（std∶∶move（s2））触发一次移动构造，对应第二行输出。 

vs.push_back（String（"Three"））触发一次移动构造，对应第四行输出。 

vs.push_back（"Four"） 触发一次移动构造，对应第七行输出。

那么，其他几次（移动）构造函数是如何触发的呢?

回忆一下，默认初始化的vector不分配内存空间。当push_back发现vector空间不足以容纳新元素时，分配新的空间（通常是加倍），将数据移动到新的空间中（由于 String定义了移动构造函数，这里确实是"移动"而非"拷贝"），然后释放旧空间。

因此，当插入 s2 时，空间由1扩为2，并将原有元素（one）移动到新空间，对应第三行输出。

当插入Three 时，空间由2扩为 4，将 one、Two 移动到新空间，产生两次移动构造，对应第五、六两行输出。

尝试在创建 vector 后为它预留足够空间∶vs.reserve（4），则输出为∶ 

Copy Constructor One 

Move Constructor Two 

Move Constructor Three 

Move Constructor Four 

One Two Three Four

因空间扩展引起的移动构造就不存在了。