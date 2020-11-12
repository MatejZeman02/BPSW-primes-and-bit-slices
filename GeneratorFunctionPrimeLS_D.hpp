#ifndef GENERATORFUNCTIONPRIMELS_D_HPP
#define GENERATORFUNCTIONPRIMELS_D_HPP

#include "GeneratorFunctionPrime.hpp"
#include "BPSWTest.hpp"



class GeneratorFunctionPrimeLS_D : public GeneratorFunctionPrime {
    private:
    BPSWTest _t;

    public:
    GeneratorFunctionPrimeLS_D();
    
    int GenFunct(const __uint128_t & N, const mpz_t & mpz_X);
};

#endif