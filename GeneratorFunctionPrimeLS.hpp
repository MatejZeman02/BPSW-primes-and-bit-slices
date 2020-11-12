#ifndef GENERATORFUNCTIONPRIMELS_HPP
#define GENERATORFUNCTIONPRIMELS_HPP

#include "GeneratorFunctionPrime.hpp"
#include "BPSWTest.hpp"



class GeneratorFunctionPrimeLS : public GeneratorFunctionPrime {
    private:
    BPSWTest _t;

    public:
    GeneratorFunctionPrimeLS();
    
    int GenFunct(const __uint128_t & N, const mpz_t & mpz_X);
};

#endif