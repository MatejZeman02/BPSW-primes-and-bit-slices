#include "GeneratorFunctionPrime.hpp"

#include <iostream>
#include <chrono>

using namespace std::chrono;


using std::endl;
using std::cout;

GeneratorFunctionPrime::GeneratorFunctionPrime(){
    _BeginTime = high_resolution_clock::now();
}

long double GeneratorFunctionPrime::DurationMinutes(){
    auto duration = duration_cast<milliseconds>(high_resolution_clock::now() - _BeginTime);
    return duration.count() / (1000.0l * 60.0l);
    // return duration.count();
}

unsigned long long GeneratorFunctionPrime::ProbablePrimesCnt() const {
    return _ProbablePrimesCnt;
}

unsigned long long GeneratorFunctionPrime::PrimesCnt() const {
    return _PrimesCnt;
}
