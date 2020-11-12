#include "BitStatistics.hpp"

#include <iostream>


using std::endl;
using std::cout;

void BitStatisticsTest(){

    // BitStatistics A;
    // A.ComputePrimesInPower2Range(10);
    
    for (unsigned int i=1; i<=63; i++)
    {
        {
            cout << "Bit statistics for power: " << i << endl;
            BitStatistics A;
            A.ComputePrimesInPower2Range(i);
            cout << endl;

        }

    }
    
}
