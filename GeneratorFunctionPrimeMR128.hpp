#ifndef GENERATORFUNCTIONPRIMEMR128_HPP
#define GENERATORFUNCTIONPRIMEMR128_HPP

#include "GeneratorFunctionPrime.hpp"
#include "BPSWTest.hpp"



class GeneratorFunctionPrimeMR128 : public GeneratorFunctionPrime {
    private:
    BPSWTest _t;

    public:
    GeneratorFunctionPrimeMR128();
    
    int GenFunct(const __uint128_t & N, const mpz_t & mpz_X);
};

#endif