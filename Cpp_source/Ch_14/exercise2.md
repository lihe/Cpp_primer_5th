```c++
class Sales_data {
    friend istream& operator >> (istream &, Sales_data &);
    friend ostream& operator << (ostream &, Sales_data &);
public:
    Sales_data& operator += (const Sales_data &);
    Sales_data operator + (const Sales_data &, const Sales_data &);
}
```

