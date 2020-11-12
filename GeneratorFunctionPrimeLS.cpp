#include "GeneratorFunctionPrimeLS.hpp"


GeneratorFunctionPrimeLS::GeneratorFunctionPrimeLS() :_t(65) {
}


int GeneratorFunctionPrimeLS::GenFunct(const uint128_t & X, const mpz_t & mpz_X) {
    
    if(_t.iLucasSelfridge(mpz_X)) {
        _PrimesCnt++;
    }                  
    return 0;
}