#ifndef GENERATORFUNCTIONPRIMEMR_HPP
#define GENERATORFUNCTIONPRIMEMR_HPP

#include "GeneratorFunctionPrime.hpp"
#include "BPSWTest.hpp"



class GeneratorFunctionPrimeMR : public GeneratorFunctionPrime {
    private:
    BPSWTest _t;

    public:
    GeneratorFunctionPrimeMR();
    
    int GenFunct(const __uint128_t & N, const mpz_t & mpz_X);
};

#endif