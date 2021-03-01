```c++
class date{
public:
    friend ostream& operator << (ostream&, const date&);

    date() {};
    date(int y, int m, int d) : year(y), month(m), day(d) {}

private:
    int year, month, day;
};

ostream& operator << (ostream &os, const data &d) {
    const char sep = '\t';
    os << "year: " << d.year << sep << "month: " << d.month << sep << "day: " << d.day << endl;
    return os;
}
```

