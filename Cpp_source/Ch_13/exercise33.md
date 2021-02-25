首先，我们需要将给定 Folder 的指针添加到当前Message的 folders集合中。这样，参数类型就不能是 Folder，必须是引用类型。

否则，调用 save 时会将实参拷贝给形参，folders.insert添加的就是形参（与局部变量一样在栈中，save执行完毕就被销毁）的指针，而非原始 Folder 的指针。

而参数为引用类型，就可以令形参与实参指向相同的对象，对形参f 取地址，得到的就是原始Folder（实参）的指针。

其次，我们需要调用 addMsg 将当前 Message 的指针添加到 Folder 的 messages 集合中，这意味着我们修改了Folder 的内容，因此参数不能是 const的。

