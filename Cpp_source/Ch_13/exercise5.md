```c++
HasPtr::HasPtr(const HasPtr &hp){
    ps = new string(*hp.ps);  // 拷贝ps指向的对象，而不是拷贝指针本身
    i = hp.i;
}
```

