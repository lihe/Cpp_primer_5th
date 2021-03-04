```c++
class date{
public:
    friend ostream& operator << (ostream&, const date&);
    friend istream& operator >> (istream&, const date&);

    date() {};
    date(int y, int m, int d) : year(y), month(m), day(d) {}

private:
    int year, month, day;
};

ostream& operator << (ostream &os, const date &d) {
    const char sep = '\t';
    os << "year: " << d.year << sep << "month: " << d.month << sep << "day: " << d.day << endl;
    return os;
}

istream& operator >> (istream &is, const date &d) {
    is >> d.year >> d.month >> d.day;
    if (!is) {
        d = Date(0, 0, 0);
    }
    return is;
}
```

