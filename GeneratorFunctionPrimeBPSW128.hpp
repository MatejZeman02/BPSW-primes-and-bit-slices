#ifndef GENERATORFUNCTIONPRIMEBPSW128_HPP
#define GENERATORFUNCTIONPRIMEBPSW128_HPP

#include "GeneratorFunctionPrime.hpp"
#include "BPSWTest.hpp"



class GeneratorFunctionPrimeBPSW128 : public GeneratorFunctionPrime {
    private:
    BPSWTest _t;

    public:
    GeneratorFunctionPrimeBPSW128();
    
    int GenFunct(const __uint128_t & N, const mpz_t & mpz_X);
};

#endif