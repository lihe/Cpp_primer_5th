Message类包含两个数据成员∶content为string类型，folders 为 set。

这两个标准库类都有完备的拷贝控制成员，因此Message使用合成的拷贝控制成员的话，简单拷贝这两个成员也能实现正确拷贝。

但是，本问题的需求不仅如此。

当拷贝 Message 时，不仅要拷贝这个 Message 在哪些 Folder 中，还要将 Message 加到每个 Folder 中——调用 addMsg。

类似的，当销毁Message时，需要将它从所有Folder中删除——调用remMsg。

因此，不能依赖合成的拷贝控制成员，必须设计自己的版本来完成这些簿记工作。