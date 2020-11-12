#include "GeneratorFunctionPrimeBPSW128.hpp"


GeneratorFunctionPrimeBPSW128::GeneratorFunctionPrimeBPSW128() :_t(65) {
}


int GeneratorFunctionPrimeBPSW128::GenFunct(const uint128_t & X, const mpz_t & mpz_X) {
    if(_t.IsPrimeBPSW(mpz_X)) {
        // _PrimesCnt++
        _PrimesCnt++;
    }                  
    return 0;
}