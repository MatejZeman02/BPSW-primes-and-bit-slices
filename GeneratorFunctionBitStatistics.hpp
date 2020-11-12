#ifndef GENERATORFUNCTIONBITSTATISTICS_HPP
#define GENERATORFUNCTIONBITSTATISTICS_HPP

#include "GeneratorFunction.hpp"
#include "BPSWTest.hpp"
#include "BitStatistics.hpp"


#include "int128_t.hpp"
using namespace primecount;

#include <gmp.h>
#include <vector>



class GeneratorFunctionBitStatistics : GeneratorFunction {
    private:
    mpz_t _mpz_X;
    BPSWTest _t;
    BitStatistics * _pBS;

    public:
    GeneratorFunctionBitStatistics(BitStatistics *pBS);
    ~GeneratorFunctionBitStatistics();

    int GenFunct(const __uint128_t & N, const mpz_t & mpz_X);
    
};

#endif