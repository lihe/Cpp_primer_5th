//
// Created by Leslie on 2021/1/26.
//

#ifndef CPP_PRIMER_5TH_SALES_DATA_H
#define CPP_PRIMER_5TH_SALES_DATA_H
#include <string>
#include <iostream>
#include <utility>

using namespace std;

class Sales_data {
    friend std::ostream &print(std::ostream&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);
public:
    // constructors
// using the synthesized version is safe only
// if we can also use in-class initializers
#if defined(IN_CLASS_INITS) && defined(DEFAULT_FCNS)
    Sales_data() = default;
#else
    Sales_data(): units_sold(0), revenue(0.0) { }
#endif
#ifdef IN_CLASS_INITS
    Sales_data(const std::string &s): bookNo(s) { }
#else
    explicit Sales_data(std::string s):
            bookNo(std::move(s)), units_sold(0), revenue(0.0) { }
#endif
    Sales_data(std::string s, unsigned n, double p):
            bookNo(std::move(s)), units_sold(n), revenue(p*n) { }
    explicit Sales_data(std::istream &);

    // operations on Sales_data objects
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
private:
    std::string bookNo;
#ifdef IN_CLASS_INITS   // using the synthesized version is safe only
    unsigned units_sold = 0;
	double revenue = 0.0;
#else
    unsigned units_sold{};
    double revenue{};
#endif
};


// nonmember Sales_data interface functions
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

// used in future chapters
inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}
#endif //CPP_PRIMER_5TH_SALES_DATA_H
