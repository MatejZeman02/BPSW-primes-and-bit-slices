#include "GeneratorFunctionPrimeAPRCL.hpp"

extern "C" {
#include "mpz_aprcl.h"
}


int GeneratorFunctionPrimeAPRCL::GenFunct(const uint128_t & X, const mpz_t & mpz_X) {

    if (mpz_aprcl(const_cast<mpz_t&>(mpz_X))) {
        _PrimesCnt++; 
    }  
    return 0;
}