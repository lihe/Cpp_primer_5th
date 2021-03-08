在练习7.40 中，我们实现了 Date类。因为我们可以比较两个日期是否相等，因此需要实现相等运算符。

```c++
class Date {
    friend bool operator == (const Date &d1, const Date &d2);
    friend bool operator != (const Date &d1, const Date &d2);
    
};

bool operator == (const Date &d1, const Date &d2) {
    return d1.year == d2.year && d1.month == d2.month && d1.day == d2.day;
}

bool operator != (const Date &d1, const Date &d2) {
    return !(d1 == d2);
}
```

