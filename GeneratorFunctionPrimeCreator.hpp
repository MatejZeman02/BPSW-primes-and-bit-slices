#ifndef GENERATORFUNCTIONPRIMECREATOR_HPP
#define GENERATORFUNCTIONPRIMECREATOR_HPP

#include <vector>

#include "GeneratorFunctionPrime.hpp"
#include "BPSWTest.hpp"



class GeneratorFunctionPrimeCreator : public GeneratorFunctionPrime {
    private:
    BPSWTest _t;
    unsigned long long _NumberOfPrimesToCreate;

    public:
    GeneratorFunctionPrimeCreator(unsigned long long NumberOfPrimes);

    std::vector<uint128_t> CreatedPrimes;

    
    int GenFunct(const __uint128_t & N, const mpz_t & mpz_X);
};

#endif