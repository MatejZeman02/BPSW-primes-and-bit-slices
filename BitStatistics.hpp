#ifndef BITSTATISTICS_HPP
#define BITSTATISTICS_HPP

#include "int128_t.hpp"
using namespace primecount;

class BitStatistics{
    public:
    void SaveFile() const;

    // used for file name
    int BitIndex = 0;

    // Number of primes which have X bits set to 1
    // PrimesWithOneCnt[0]=0  zero is not a prime
    // PrimesWithOneCnt[0]=1 only if 2 is being tested. It is the only prime which have only one bit set to 1
    unsigned long long PrimesWithOneCnt[65];
    
    // OnesPosCnt[4] = number of primes in a range which have bit number 4 (counted from 0, bit 0 determines whether number is odd) set to 1
    // OnesPosCnt[0] is the highest number as all primes are odd except of prime 2
    unsigned long long OnesPosCnt[65];
    

    // generates primes within given range and computes both statistics
    // BPSW test based on GMP is used for primality test
    // primes are being generated using primorial 23
    void GetPrimesInRange(unsigned long long Begin, unsigned long long End);

    // computes range of numbers defined by specified bit and calls GetPrimesInRange for computation
    // sets variable BitIndex used later for output filename
    void ComputePrimesInPower2Range(const unsigned int Bitindex);

    // void TestBit32(const unsigned int PowerBegin=1, const unsigned int PowerEnd=31 );

    // constructor only sets both arrays to 0
    BitStatistics();

    /*
    For one input prime number computes number of bits set and on which positions and updates both arrays
    */
    void ComputePrimeStats(unsigned long long Prime);

};
#endif
