#ifndef __UINT128TOMPZ_HPP
#define __UINT128TOMPZ_HPP

#include <gmp.h>

#include "int128_t.hpp"
using namespace primecount;

namespace Utils {

void UInt128tompz(uint128_t In, mpz_t &Out) {
    
    mpz_set_ui(Out,0);
    while (In > UINT64_MAX) {
        mpz_add_ui(Out, Out, UINT64_MAX);
        In -= UINT64_MAX;
    }
    unsigned long long offset = In;
    mpz_add_ui(Out, Out, offset);
}
}

#endif