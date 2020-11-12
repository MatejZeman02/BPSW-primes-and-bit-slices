#include <iostream>
#include <memory>
#include <fstream>


#include "SieveGenerator.hpp"
#include "GeneratorFunctionBitStatistics.hpp"
#include "PrimesRange.hpp"
#include "PrimesRangeService.hpp"


using std::cout;

void SieveGeneratorTest(){
    SieveGenerator A(C_SieveGeneratorDefaultMaxPrime);
    GeneratorFunctionBitStatistics GF(nullptr);

    uint128_t Begin = UINT64_MAX; // UINT64_MAX + 1 is evaluated at compile time as 0 !!!  
    Begin++;
    uint128_t End = Begin + 1000000000UL;

    GeneratorFunction * pGF = (GeneratorFunction *) &GF;
    A.Work(Begin, End, pGF);

}

/* Works fine up to 31 (computation time is several hours). For higher primorials some form of optimization is needed.*/
void EratosthenesEffectivity(){

    cout <<"EratosthenesEffectivity"<<endl;

    uint32_t *Primes=nullptr;
    std::shared_ptr<PrimesRange> P = PrimesRangeService::GetPrimesRange(2,101);
    unsigned long long PrimesCount = P->PrimesCount;
    Primes = P->PrimesArray32();
    
    mpz_t mpz_primor;
    mpz_t mpz_res;
    mpz_init2(mpz_primor,64);
    mpz_init2(mpz_res,64);

    std::ofstream myfile;
    myfile.open("EratosthenesEffectivity.txt");
    myfile  << "Prime" << " " << "Primorial" << " "<< "Coprimes" << " "<< "Effectivity" <<endl;
  

    for (unsigned long long idx=0; idx<PrimesCount; idx++) {
        mpz_primorial_ui(mpz_primor, Primes[idx]);
        if (mpz_cmp_ui(mpz_primor, UINT64_MAX) > 0 ){
            cout << "Cannot compute for primorial exceding 64 bits. Fatal, mission aborted." << endl;
            break;
        }
        unsigned long long Primorial = mpz_get_ui(mpz_primor);

        //count coprimes to primorial
        unsigned long long TACount=0;
        for (unsigned long long i = 1; i<Primorial;){
            mpz_gcd_ui(mpz_res, mpz_primor, i);
            if(mpz_cmp_ui(mpz_res,1)==0){
                TACount++;
            }
            i+=2;
        }
        long double effectivity = 100.0L * (long double) TACount / (long double) Primorial;
        cout << Primes[idx] << " " << Primorial  << " "<< TACount << " " << effectivity <<endl;
        myfile << Primes[idx] << " " << Primorial  << " "<< TACount << " " << effectivity <<endl;
        myfile.flush();
    }
    myfile.close();
    mpz_clear(mpz_primor);
    mpz_clear(mpz_res);
}