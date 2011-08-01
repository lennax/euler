#include <iostream>
#include "PrimeFinder.hpp"

// n² + an + b, where |a| < 1000 and |b| <  1000
class PrimeQuadratic 
{
public:
	PrimeQuadratic() {

		PrimeFinder primeList(40000);
		uint32_t maxPrimes = 0;
		int bestA = 0;
		int bestB = 0;
		//for (int a=-61;a<-60;a++) for (int b=971;b<972;b++) {
		for (int a=-999;a<1000;a++) for (int b=-999;b<1000;b++) {
		
				uint32_t consecPrimes = 0;
			for (int n=0;n<1555550;n++) {
				int current = n*n+a*n+b;
				if (current < 0) 
					break;
				if (!primeList.getPrime(current)) 
					break;
				//std::cout << "prime: " << current << std::endl;
				consecPrimes++;
				if (consecPrimes > maxPrimes) { 
					maxPrimes = consecPrimes;
					bestA = a;
					bestB = b;
				}
			}
		}
		std::cout << "Max consecutively generated primes: " << maxPrimes << std::endl;
		std::cout << "A and B: " << bestA << "\t" << bestB << std::endl;
	}
};

int main (int argc, char const* argv[])
{
	PrimeQuadratic primeQuadraticInstance;
	return 0;
}


