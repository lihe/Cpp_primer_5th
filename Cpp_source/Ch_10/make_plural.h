//
// Created by Leslie on 2021/1/26.
//

#ifndef CPP_PRIMER_5TH_MAKE_PLURAL_H
#define CPP_PRIMER_5TH_MAKE_PLURAL_H
#include <cstddef>
#include <string>
#include <iostream>
using namespace std;

// return the plural version of word if ctr is greater than 1
inline string make_plural(size_t ctr, const string &word, const string &ending){
    return (ctr > 1) ? word + ending : word;
}

#endif //CPP_PRIMER_5TH_MAKE_PLURAL_H
