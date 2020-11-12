
#include "PrimesRangeServiceTest.cpp"
#include "BitRangeTest.cpp"
#include "BitStatisticsTest.cpp"
#include "BPSWTestTest.cpp"
#include "int128Test.cpp"
#include "SieveGeneratorTest.cpp"
#include "GeneratorFunctionBitStatistics.hpp"
#include "SliceTBalance.hpp"
#include "SliceTBalanceTest.cpp"


// C code must be used from C++ code using extern in order to disable messing with functions names needed for overloading (allowed only in C++, not in C)
// Otherwise linking would fail
// Every decent header (and it is not the case of this one) should contain #ifdef __cplusplus extern "C" { } #endif or macros G_BEGIN_DECLS and G_END_DECLS
extern "C" {
#include "mpz_aprcl.h"
}


using namespace std::chrono;
using std::endl;
using std::cout;



/*
kriticke nastaveni> volat g++ s parametrem -lgmp
"-lstdc++fs"
"-std=c++17"

/usr/bin/g++ -g 
/home/bubakulus/projects/primes/TestGMP.cpp 
-o /home/bubakulus/projects/primes/TestGMP 
-L/gmp_install/lib 
-lgmp

Include path - neni potreba pridavat
/usr/include/x86_64-linux-gnu/dvehvezdy
*/



int main()
{   
    cout << "gmp version: " << __gmp_version << endl;

    // PrimesRangeServiceTest();

    // BitRangeTest();

    // BitStatisticsTest();

    // BPSWTestTest();

    // int128Test();

    // SieveGeneratorTest();

    // EratosthenesEffectivity();

    // SliceTBalanceTest();

    // MethodTestsNearBegin();
    // MethodTestsNearEnd();
    // MethodTestsOnPrime();

    SliceTBalanceTest(); 
}

/*
ToDo:
vlastní překlad gmp
vlastní modifikace gmp
optimalizace pro miller rabina a násobky d -- jiný průchod prostorem???
doplnit const
reentrantnost aprcl?

zkusit volat millera rabin a selfridge z mpz knihovny a zmerit cas. jak je mozne, ze nepocitaji jacobiho?
zapnout v mpz optimalizaci, ze bpsw je spolehliva do 2na64

podivat se na repetetive square misto powm
porovnat implementaci rabina s rabinem v mpz - cast powm a jacobi

podivat se na kod posledni verze gmp 6.2 knihovny - optimalizace powm poro base 2
zjistit, v cem je leppsi mpfr knihovna a zda neobsahuje lepsi kody
*/