#include "GeneratorFunctionPrimeMR.hpp"


GeneratorFunctionPrimeMR::GeneratorFunctionPrimeMR() :_t(65) {
}


int GeneratorFunctionPrimeMR::GenFunct(const uint128_t & X, const mpz_t & mpz_X) {
    
    if(_t.iMillerRabinBase2(mpz_X)) {
        _PrimesCnt++;
    }                  
    return 0;
}