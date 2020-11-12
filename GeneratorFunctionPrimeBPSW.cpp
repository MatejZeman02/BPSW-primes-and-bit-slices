#include "GeneratorFunctionPrimeBPSW.hpp"


GeneratorFunctionPrimeBPSW::GeneratorFunctionPrimeBPSW() :_t(65) {
}


int GeneratorFunctionPrimeBPSW::GenFunct(const uint128_t & X, const mpz_t & mpz_X) {
    // if (mpz_bpsw_prp(const_cast<mpz_t&>(mpz_X))) {
    //     _PrimesCnt++;
    // }
    
    if(_t.IsPrimeBPSW(mpz_X)) {
        // _PrimesCnt++
        _PrimesCnt++;
    }                  
    return 0;
}