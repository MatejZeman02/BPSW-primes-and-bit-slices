#ifndef GENERATORFUNCTIONPRIMEBPSW2_HPP
#define GENERATORFUNCTIONPRIMEBPSW2_HPP

#include "GeneratorFunctionPrime.hpp"
#include "BPSWTest.hpp"



class GeneratorFunctionPrimeBPSW2 : public GeneratorFunctionPrime {
    private:

    public:
    
    int GenFunct(const __uint128_t & N, const mpz_t & mpz_X);
};

#endif