#include "GeneratorFunctionPrimeMR128.hpp"


GeneratorFunctionPrimeMR128::GeneratorFunctionPrimeMR128() :_t(65) {
}


int GeneratorFunctionPrimeMR128::GenFunct(const uint128_t & X, const mpz_t & mpz_X) {
    
    if(_t.iMillerRabinBase2(X)) {
        _PrimesCnt++;
    }                  
    return 0;
}