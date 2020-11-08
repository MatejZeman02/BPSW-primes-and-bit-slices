# BPSW-primes-and-bit-slices
The source code coveres two different topics. 

1. Analysis of BPSW primality test (effectivity and reliability) on 65-bit long numbers. 
Main aim was verification of reliability of BPSW test in a range up to 2^65. The test has already been verified up to 2^64. The code immplements various versions of primality tests, Erathosthenes sieve algorithm for skipping multiples of small primes and algorithms for measuring duration of methods over various samples of numbers. Conclusion: verification of BPSW primality test is too difficult task for developed algorithms and a home computer. 

2. Distribution of primes on intervals of lengths given by powers of two and on its bit slices. 
A study of distribution of primes on intervals specified by conditions on mandatory settings of two bits (in binary representation of integer type in C++) or slices defined by one mandatory bit and a certain number of set bits.

Both parts supported year long thesis of the author required by school. See the following link: http://archiv.prirodniskola.cz/profilove-prace.html

Results computed via this program can be found here:
https://docs.google.com/spreadsheets/d/1YZKVsGMMEgvizjicBX59jQYdXLOTNTPxQfWsvlOgZO4/edit?usp=sharing

Final thesis (in the Czech language) is here:
https://docs.google.com/document/d/191X1eMjp72DpxHHzX8mmrTakhvO9K6nQU0wAJulR4cw/edit?usp=sharing
