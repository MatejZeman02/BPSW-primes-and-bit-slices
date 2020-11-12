#ifndef GENERATORFUNCTIONPRIMEAPRCL_HPP
#define GENERATORFUNCTIONPRIMEAPRCL_HPP

#include "GeneratorFunctionPrime.hpp"
// #include "BPSWTest.hpp"

class GeneratorFunctionPrimeAPRCL : public GeneratorFunctionPrime {


    public:
    
    int GenFunct(const __uint128_t & N, const mpz_t & mpz_X);
};

#endif