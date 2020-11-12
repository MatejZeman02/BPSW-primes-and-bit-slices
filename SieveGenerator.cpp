#include "SieveGenerator.hpp"
#include "UInt128tompz.hpp"

#include <iostream>
#include <math.h>
#include <mutex>
#include <fstream>

#include <gmp.h>


using std::endl;
using std::cout;
using std::string;
using std::to_string;
using std::vector;
using namespace std::chrono;

// static variable must be defined outside of header, beware: declaration is not a definition
unsigned int SieveGenerator::p_MaxPrime=0;
unsigned long long SieveGenerator::p_TestArrayCount = 0;
std::vector<uint32_t> SieveGenerator::p_TestArray(0);
// std::vector<uint64_t> SieveGenerator::p_TestArray(0);
unsigned long long SieveGenerator::p_Primorial=1;
std::mutex SieveGenerator::p_TestArray_mutex;


SieveGenerator::SieveGenerator() : SieveGenerator(C_SieveGeneratorDefaultMaxPrime)  {
}

SieveGenerator::SieveGenerator(unsigned int MaxPrime){
    // ToDo: Test with more threads  ??? is it ok with ordinary object and no smart pointers
    // array may be in process of init from other thread???
    const std::lock_guard<std::mutex> lock(p_TestArray_mutex); 

    if (p_MaxPrime==0){
        mpz_t mpz_primor;
        mpz_t mpz_res;
        mpz_init2(mpz_primor,64);
        mpz_init2(mpz_res,64);
        mpz_primorial_ui(mpz_primor, MaxPrime);
        // if (mpz_cmp_ui(mpz_primor, UINT64_MAX) > 0 ){
        if (mpz_cmp_ui(mpz_primor, UINT32_MAX) > 0 ){
            throw("SieveGenerator cannot initialize for primorial exceding 32 bits. Fatal, mission aborted."); //ToDo Memory leak?? How to throw or exit??
        }
        p_Primorial = mpz_get_ui(mpz_primor);
        
        // load destination array size if known prom previous computations
        unsigned long long BufferSize=0;
        // for(unsigned int  i = 0; i < C_PrimorialPrimes.size() && i < C_Effectivity.size(); i++){
        for(unsigned int  i = 0; i < C_PrimorialPrimes.size(); i++){
            if (C_PrimorialPrimes[i]<=MaxPrime) {
                BufferSize = C_TestArraySizes[i];  
            }
        }
        if (BufferSize==0) BufferSize = 1+ p_Primorial * .15; 
        p_TestArray.reserve(BufferSize);
        
        // fill Test array with coprimes to primorial
        unsigned long long TACount=0;
        for (unsigned long long i = 1; i<p_Primorial;){
        // for (unsigned long i = 1; i<p_Primorial;){
            mpz_gcd_ui(mpz_res, mpz_primor, i);
            if(mpz_cmp_ui(mpz_res,1)==0){
                p_TestArray.push_back(i);
                TACount++;
            }
            i+=2;
        }

        p_TestArray.shrink_to_fit();
        mpz_clear(mpz_primor);
        mpz_clear(mpz_res);

        p_TestArrayCount = TACount;        
        // p_TestArrayCount=p_TestArray.size();
        p_MaxPrime = MaxPrime;
        long double MeasuredEffectivity = (long double) p_TestArrayCount / (long double) p_Primorial;

        cout << "Max Prime: " << MaxPrime << endl;
        cout << "Primorial: " << p_Primorial << endl;
        cout << "Test Array Size: " << p_TestArrayCount << endl;
        cout << "Effectivity: " << MeasuredEffectivity  << endl;         
    }
    else if (p_MaxPrime!=MaxPrime){
        throw("SieveGenerator already initialized to a different primorial. Fatal, mission aborted.");
    }
}

uint128_t SieveGenerator::Work(const uint128_t & Begin, const uint128_t & End, GeneratorFunction * GF) const {
    mpz_t mpz_kp, mpz_X;

    #undef RETURN
    #define RETURN(n)           \
    {                         \
        mpz_clear(mpz_kp);          \
        mpz_clear(mpz_X);          \
        return(n);                \
    }

    mpz_init2(mpz_kp, 65);
    mpz_init2(mpz_X, 65);
    uint128_t res = 0;
    uint128_t k = Begin/p_Primorial;
    uint128_t kp = k * p_Primorial;  // primorial p multiplied by some integer k

    cout  << "Sieve Begin: " << Begin << endl;        
    cout  << "Sieve End  : " << End << endl;
    cout  << "Sieve End-Begin: " << End - Begin << endl;        
    // cout  << "End - UINT64_MAX: " << (uint128_t) End - (uint128_t) UINT64_MAX << endl;
    // cout  << "End - 2 * UINT64_MAX: " << (uint128_t) End - (uint128_t) UINT64_MAX - (uint128_t) UINT64_MAX << endl;        
    // cout  << "UINT64_MAX: " <<  UINT64_MAX << endl;        
    if (End / ( (uint128_t) UINT64_MAX+  (uint128_t)1) >1) {
        cout << "Serious warning!!!!! End looks too big" << endl;
    }
    
    unsigned long long i=0;
    double OldPerc = -1;
    double NewPerc = 0;

    uint128_t tmp;
    tmp = p_TestArray[p_TestArrayCount-1] + kp; 
    if (tmp < Begin){
        // Begin is very close to the next multiple of Primorial 
        // so whole TestArray would be exhausted and i would out be of bounds
        // all numbers between kp + last item of TestArrayand the next multiple of primorial must must have common divisor (not primes) 
        // -> go directly to the next primorial and leave i index at 0
        kp += p_Primorial;
        k++;
        cout << "Begin after last TestArray item. Wow !!!" << endl;
    } else {
        // search where to start with testing and set index i
        // for(; p_TestArray[i]+kp < Begin; i++);  // this for cycle works only for bit64 variables
        for(tmp = p_TestArray[i]+kp; tmp < Begin; i++ ){
            tmp = p_TestArray[i]+kp;
        };
        
        // whole TestArray has been depleated in a search 
        if(i==p_TestArrayCount) {
            // go to the next primorial
            kp += p_Primorial;
            k++;
            i = 0;
            cout << "TestArray depleated. Wow !!!" << endl;
        }
    //  TestArr[i]+kp ma byt vesti nez begin, pokud ne projedeme primorial primes
    }



    cout << "Primorials skipped: " << k << endl;
    cout << "Nearest left multiple of primorial: " << kp << endl;
    cout << "... till Begin: " << Begin - kp << endl;



    Utils::UInt128tompz(kp, mpz_kp);
    // // check correct computation of kp
    // cout << "kp:     " ;
    // cout << kp << endl;
    // cout << "mpz_kp: " ;
    // mpz_out_str(stdout, 10, mpz_kp);
    // cout << endl;

    if (kp == 0) {
        // test all primes from primorial construction between Begin and End as the algorithm does not test them
        for (auto & Prime : C_PrimorialPrimes) {
            if (Begin<=Prime) {
                if (Prime <= End && Prime <=p_MaxPrime) {
                    mpz_set_ui(mpz_X, Prime);
                    if (GF->GenFunct((uint128_t) Prime, mpz_X)!=0) {
                        res = Prime;
                        RETURN(Prime);
                    }
                } else {
                    break;
                }                
            }
        }
        cout << "Primorial primes tested" << endl;
    }



    auto TBegin = high_resolution_clock::now();
    // i is now a valid index within the array bounds
    while(true)
    {
        uint128_t X = kp+p_TestArray[i];
        mpz_add_ui(mpz_X, mpz_kp, p_TestArray[i]);

        if(X > End) break;            

        // mpz_t Comp;
        // mpz_init2(Comp, 512);
        // UInt128tompz(X, Comp);
        // if (mpz_cmp(mpz_X, Comp)!=0){
        //     cout << "not equel ..........." << endl;
        // }

        if (GF->GenFunct(X, mpz_X)!=0) {
            res = X;
            RETURN(X);
        };
                  
        i++;
        if(i==p_TestArrayCount) 
        {
            i=0;
            kp += p_Primorial;
            mpz_add_ui(mpz_kp, mpz_kp, p_Primorial);
            NewPerc = (100.0*(kp-Begin)/(End-Begin));
            NewPerc = (std::floor(NewPerc*10.0))/10.0;
            if(NewPerc !=OldPerc){
                OldPerc = NewPerc;
                std::cout  << OldPerc << " " << std::flush;
            }
        }
    }
    std::cout  << endl;
    auto TEnd = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(TEnd - TBegin);
    cout << "Sieve duration: " << duration.count() << endl;
    cout << endl;

    RETURN(0);
}
