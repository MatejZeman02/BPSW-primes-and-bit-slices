#ifndef GENERATORFUNCTIONPRIME_HPP
#define GENERATORFUNCTIONPRIME_HPP

#include "GeneratorFunction.hpp"
#include "BPSWTest.hpp"

#include "int128_t.hpp"
using namespace primecount;

#include <chrono>
#include <gmp.h>

using namespace std::chrono;


class GeneratorFunctionPrime : GeneratorFunction {
    
    protected:
    unsigned long long _PrimesCnt = 0;
    unsigned long long _ProbablePrimesCnt = 0;   
    std::chrono::time_point<std::chrono::high_resolution_clock> _BeginTime; //  = std::high_resolution_clock::now(); 
    

    public:
    GeneratorFunctionPrime();
    // int GenFunct(const __uint128_t & N, const mpz_t & mpz_X);
    unsigned long long PrimesCnt() const;
    unsigned long long ProbablePrimesCnt() const;
    long double DurationMinutes();
};

#endif