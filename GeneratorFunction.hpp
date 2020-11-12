#ifndef __GENERATORFUNCTION_HPP
#define __GENERATORFUNCTION_HPP

#include <gmp.h>

#include "int128_t.hpp"
using namespace primecount;


class GeneratorFunction{
    public:
    // virtual GeneratorFunction();
    // ~GeneratorFunction();
    virtual int GenFunct(const __uint128_t & N, const mpz_t & mpz_X) = 0;
};

#endif
