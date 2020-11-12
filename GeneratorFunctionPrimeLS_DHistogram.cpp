#include "GeneratorFunctionPrimeLS_DHistogram.hpp"


GeneratorFunctionPrimeLS_DHistogram::GeneratorFunctionPrimeLS_DHistogram() :_t(65) {
}


int GeneratorFunctionPrimeLS_DHistogram::GenFunct(const uint128_t & X, const mpz_t & mpz_X) {
    

    _t.iLucasSelfridge_DHistogram(mpz_X);
    return 0;
}