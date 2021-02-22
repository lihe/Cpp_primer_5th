如下几个地方使用了拷贝构造函数∶ 

1. local = arg 将 arg 拷贝给 local。
2. *heap = local;将 local拷贝到heap 指定的地址中。
3. Point pa[4]=（ local，* heap };将local和*heap拷贝给数组的前两个元素。  
4. return *heap;。

