#ifndef GENERATORFUNCTIONPRIMELS_DHISTOGRAM_HPP
#define GENERATORFUNCTIONPRIMELS_DHISTOGRAM_HPP

#include "GeneratorFunctionPrime.hpp"
#include "BPSWTest.hpp"


class GeneratorFunctionPrimeLS_DHistogram : public GeneratorFunctionPrime {
    private:

    public:
    BPSWTest _t;
    GeneratorFunctionPrimeLS_DHistogram();
    
    int GenFunct(const __uint128_t & N, const mpz_t & mpz_X);
};

#endif