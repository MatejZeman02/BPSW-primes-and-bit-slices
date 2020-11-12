#include "GeneratorFunctionBitStatistics.hpp"

#include "BitStatistics.hpp"

#include <iostream>


using std::endl;
using std::cout;


GeneratorFunctionBitStatistics::GeneratorFunctionBitStatistics(BitStatistics *pBS) :_t(64) {
    _pBS = pBS;
    mpz_init2(_mpz_X, 64);
}

GeneratorFunctionBitStatistics::~GeneratorFunctionBitStatistics() {
    mpz_clear(_mpz_X);
}


int GeneratorFunctionBitStatistics::GenFunct(const uint128_t & X, const mpz_t & mpz_X) {
    mpz_set_ui(_mpz_X, X);    
    if(_t.IsPrimeBPSW(_mpz_X)) {
        // std::cout << X << endl;
        _pBS->ComputePrimeStats(X); //???
    }                     

    return 0;
}