#include "GeneratorFunctionPrimeLS_D.hpp"


GeneratorFunctionPrimeLS_D::GeneratorFunctionPrimeLS_D() :_t(65) {
}


int GeneratorFunctionPrimeLS_D::GenFunct(const uint128_t & X, const mpz_t & mpz_X) {
    

    if(_t.iLucasSelfridge_D(mpz_X)) {
        _PrimesCnt++;
    }                  
    return 0;
}