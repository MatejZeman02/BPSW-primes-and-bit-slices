#ifndef BPSWTEST_HPP
#define BPSWTEST_HPP

#include <gmp.h>
#include "int128_t.hpp"
#include <vector>



using namespace std;
using namespace primecount;


class BPSWTest{
    private:
        mpz_t mpzB, mpzNm1, mpzd, mpzRem, mpzOne; 
        unsigned long long ulDmax;

        mpz_t mpzN;
        mpz_t mpz_X;

    
    public:
        BPSWTest(unsigned int iBits);

        ~BPSWTest();

        bool iMillerRabinBase2(const mpz_t & mpzN);
        bool iMillerRabinBase2(const uint128_t & X);
        bool iMillerRabinBase2Optimized(const mpz_t & mpzN);


        bool iLucasSelfridge(const mpz_t & mpzN);
        long iLucasSelfridge_D(const mpz_t & mpzN); //returns only D coef
        void iLucasSelfridge_DHistogram(const mpz_t & mpzN); //histogram of D coeficient
        
        static const unsigned int C_HistItems=10; //10 columns and one forall bigger values
        vector<unsigned long> DHist1;
        vector<unsigned long> DHist10;
        vector<unsigned long> DHist100;
        vector<unsigned long> DHist1000;
        long long MaxD;
        mpz_t NumberWithMaxD;

        bool IsPrimeBPSW(const unsigned long long X);
        bool IsPrimeBPSW(const uint128_t & X);
        bool IsPrimeBPSW(const mpz_t & N);
        
};
#endif  
