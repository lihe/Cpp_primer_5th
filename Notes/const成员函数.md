

```c++
class Sales_data{
    // 友元函数
    friend istream& operator >> (istream&, Sales_data&);
    friend ostream& operator << (ostream&, const Sales_data&);
    friend bool operator == (const Sales_data&, const Sales_data&);

public:
    // 构造函数的三种形式
    Sales_data() = default;
    Sales_data(const string &book) : bookNo(book) { }
    Sales_data(istream &is) {is >> *this;}

    Sales_data& operator += (const Sales_data&);
    string isbn() const {return bookNo;}
    Sales_data &combine(const Sales_data &rhs);
    double avg_price() const;
};
```



isbn 函数的一个关键之处是紧随参数列表之后的 const 关键字，这里，const的作用是==修改隐式 this指针的类型==。

默认情况下，this 的类型是==指向类类型非常量版本的常量指针==。

例如在Sales_data成员函数中，this的类型是 Sales_data *const。尽管this是隐式的，但它仍然需要遵循初始化规则，意味着（在默认情况下）我们不能把this绑定到一个常量对象上。这一情况也就使得我们不能在一个常量对象上调用普通的成员函数。

如果 isbn 是一个普通函数而且 this 是一个普通的指针参数，则我们应该把 this声明成const Sales_data *const。毕竟，在isbn的函数体内不会改变this所指的对象，所以把 this 设置为==指向常量的指针==有助于提高函数的灵活性。

然而，this 是隐式的并且不会出现在参数列表中，所以在哪儿将 this 声明成指向常量的指针就成为我们必须面对的问题。C++语言的做法是允许把const关键字放在成员函数的参数列表之后，此时，紧跟在参数列表后面的 const 表示 ==this 是一个指向常量的指针==。像这样使用 const 的成员函数被称作常量成员函数（const member function）。

可以把isbn的函数体想象成如下形式：

```c++
std::string Sales_data::isbn(const Sales_data *const this){
    return this -> isbn;
}
```

因为 this 是指向常量的指针，所以常量成员函数不能改变调用它的对象的内容。在上例中，isbn 可以读取调用它的对象的数据成员，但是不能写入新值。