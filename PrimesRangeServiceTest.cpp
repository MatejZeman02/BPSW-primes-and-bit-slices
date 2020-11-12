#include <iostream>
#include <fstream>
#include <math.h>

#include <gmp.h>
#include <stdint.h>

#include <filesystem>

#include "Li.hpp"
#include "PrimesRangeService.hpp"

using namespace std::chrono;
using std::endl;
using std::cout;



void PrimesRangeServiceTest() {

    uint32_t *Primes32=nullptr;
    unsigned long long PrimesCount32 = 0;
    unsigned long long Limit32 = 0;

    uint64_t *Primes64=nullptr;
    unsigned long long PrimesCount64 = 0;
    unsigned long long Limit64 = 0;


    cout <<"PrimesRangeServiceTest"<<endl;
    {
        // PrimesRange P(0, UINT32_MAX);
        std::shared_ptr<PrimesRange> P = PrimesRangeService::GetPrimesRange(0,UINT32_MAX);
        // std::shared_ptr<PrimesRange> P = PrimesRangeService::GetPrimesRange(5000000,5000000+100);
        unsigned long long PrC = P->PrimesCount;
        uint32_t * Primes;
        Primes32 = P->PrimesArray32();
        unsigned long long Sum=0;
        auto Begin = high_resolution_clock::now();
        for (unsigned long long i = 0 ; i < PrC; i++){
            Sum += Primes32[i];
        }
        auto End = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(End - Begin);
        cout << duration.count() << endl;
       

        cout << Sum << endl;

        Sum = 0;
        std::shared_ptr<PrimesRange> Q = PrimesRangeService::GetPrimesRange(0,UINT32_MAX);
        Begin = high_resolution_clock::now();
        for (unsigned long long i = 0 ; i<Q->PrimesCount; i++){
            Sum +=  Q->PrimesArray32()[i];
        }
        End = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(End - Begin);
        cout << duration.count() << endl;
        cout << Sum << endl;
        cout << endl;

    }
    
    cout <<"end"<<endl; 
}


    //unsigned long long Begin;
/*
    Limit32 = UINT32_MAX; 
    Primes32 = LoadFile32(PrimesCount32);
    
    if (!Primes32){
        Primes32 = Eratosthenes32(Limit32 , PrimesCount32);
        SaveArray32(Limit32, PrimesCount32, Primes32);
    }

    Begin =UINT32_MAX; 
    Begin++;
    Limit64 = 6074001001; //power 2^32.5 rounded up
    Primes64 = LoadFile64(PrimesCount64);

    if (!Primes64){
        Primes64 = Eratosthenes64(Begin, Limit64, PrimesCount64);
        SaveArray64(Begin, Limit64,  PrimesCount64, Primes64);
    }

*/
