#ifndef CPP_PRIMER_5TH_SALE_DATA_H
#define CPP_PRIMER_5TH_SALE_DATA_H
#include <string.h>

struct Sale_data{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

#endif //CPP_PRIMER_5TH_SALE_DATA_H
