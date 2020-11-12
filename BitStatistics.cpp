#include "BitStatistics.hpp"

#include <gmp.h>
#include <filesystem>

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <math.h>

#include "PrimesRangeService.hpp"
#include "SieveGenerator.hpp"
#include "GeneratorFunctionBitStatistics.hpp"


#include "BPSWTest.hpp"

using std::endl;
using std::cout;

void BitStatistics::SaveFile() const {
    // ToDo: RAII?
    std::ofstream myfile;
    myfile.open("PrimeBitStatistics_" + std::to_string(BitIndex) + ".txt");
    myfile  << "Power" << " " << "BitIndex" << " "<< "PrimesWithOneCnt" << " "<< "OnesPosCnt" <<endl;
    for(unsigned long long o=0;o<65;o++)
        {
            myfile << BitIndex << " " << o <<" "<< PrimesWithOneCnt[o] << " " << OnesPosCnt[o] <<" "<< endl;
        }
    myfile.close();
}

void BitStatistics:: GetPrimesInRange(unsigned long long Begin, unsigned long long End)
{
    GeneratorFunctionBitStatistics GF(this);
    SieveGenerator SG;

    GeneratorFunction * pGF = (GeneratorFunction *) &GF;
    SG.Work(Begin, End, pGF);

}

void BitStatistics::ComputePrimesInPower2Range(const unsigned int Bitindex){
    unsigned long long Begin = 1;
    this ->BitIndex = Bitindex;
    Begin = Begin << Bitindex;
    unsigned long long End = Begin + (Begin - 1);
    GetPrimesInRange(Begin, End);
    SaveFile();
}

BitStatistics::BitStatistics(){
    for(unsigned long long n=0; n<65; n++)
    {
        PrimesWithOneCnt[n]=0;
        OnesPosCnt[n]=0;
    }
}

void BitStatistics::ComputePrimeStats(unsigned long long Prime){
    unsigned long long OnesCnt=0;
    for(unsigned long long j=0; j<64; j++)
    {
        unsigned long long Bit=Prime & 1;
        if(Bit==1)
        {
            OnesPosCnt[j]++;
            OnesCnt++;
        }
        //std::cout << " Prime: " << Prime << "  " << " Bit: "<< Bit << endl;
        Prime>>=1;
    }
    PrimesWithOneCnt[OnesCnt]++;
    //std::cout << "PrimesWithOneCnt:" << PrimesWithOneCnt <<" "<< "OnesPosCnt:" << OnesPosCnt <<" "<< endl;
}


/*
// computes bit statistics for all 32 bit primes
void BitStatistics::TestBit32(const unsigned int PowerBegin, const unsigned int PowerEnd)
{
    std::shared_ptr<PrimesRange> P = PrimesRangeService::GetPrimesRange(0,UINT32_MAX);
    unsigned long long PrimesCount32 = P->PrimesCount;
    uint32_t * Primes32 = P->PrimesArray32();

    std::ofstream myfile;
    myfile.open("PrimesBitsStatistics2.txt");
    myfile  << "Power" << " " << "BitIndex" << " "<< "PrimesWithOneCnt" << " "<< "OnesPosCnt" <<endl;
    for(unsigned long long Power=PowerBegin; Power<=PowerEnd; Power++)
    {
        
        unsigned long long PowerStart=pow(2,Power);
        unsigned long long PowerEnd=pow(2,1+Power);
        unsigned long long PrimesWithOneCnt[33];
        unsigned long long OnesPosCnt[33];
        for(unsigned long long n=0; n<33; n++)
        {
            PrimesWithOneCnt[n]=0;
            OnesPosCnt[n]=0;
        }
        unsigned long long Start=0;
        for(;Primes32[Start]<PowerStart;Start++);
        //std::cout << "Start:" << Start << endl;
        //std::cout << Primes32[Start] << endl;
        for(unsigned long long i=Start;i<PrimesCount32 && Primes32[i]<PowerEnd;i++)
        {
            unsigned long long Prime=Primes32[i];
            unsigned long long OnesCnt=0;
            for(unsigned long long j=0;j<=31;j++)
            {
                unsigned long long Bit=Prime & 1;
                if(Bit==1)
                {
                    OnesPosCnt[j]++;
                    OnesCnt++;
                }
                //std::cout << " Prime: " << Prime << "  " << " Bit: "<< Bit << endl;
                Prime>>=1;
            }
            PrimesWithOneCnt[OnesCnt]++;
            //std::cout << "PrimesWithOneCnt:" << PrimesWithOneCnt <<" "<< "OnesPosCnt:" << OnesPosCnt <<" "<< endl;
        }
        for(unsigned long long o=0;o<33;o++)
        {
            myfile << Power << " " << o <<" "<< PrimesWithOneCnt[o] << " " << OnesPosCnt[o] <<" "<< endl;
        }
    } 
    myfile.close();
}
*/