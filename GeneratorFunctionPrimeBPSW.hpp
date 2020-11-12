#ifndef GENERATORFUNCTIONPRIMEBPSW_HPP
#define GENERATORFUNCTIONPRIMEBPSW_HPP

#include "GeneratorFunctionPrime.hpp"
#include "BPSWTest.hpp"



class GeneratorFunctionPrimeBPSW : public GeneratorFunctionPrime {
    private:
    BPSWTest _t;

    public:
    GeneratorFunctionPrimeBPSW();
    
    int GenFunct(const __uint128_t & N, const mpz_t & mpz_X);
};

#endif