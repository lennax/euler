#include <iostream>
#include <gmpxx.h> // for mpz_class 
#include <inttypes.h>
#include "utilities.cpp" // for smallFib()
#include <vector>
#include <algorithm> // for binary_search()
#include <cstdlib> // for atoi()

class Zeckendorf
{
public:
	Zeckendorf(mpz_class argMax)
	{
		// construct vector (99th term is well over 10^19)
		for ( mpz_class i = 0; i < 100; i++ ) {
			mpz_class fib = smallFib(i.get_ui());
			if ( fib < argMax ) {
				_fibs.push_back(fib);
			} 
			else break;	
		}
		std::cout << "Created vector of fibs under " << argMax << std::endl;
		// for (int k = 0; k < _fibs.size(); k++) {
		// 	std::cout << k << ": ";
		// 	std::cout << _fibs[k] << std::endl;
		// }
		// std::cout << "r: " << argMax - _fibs[_fibs.size()-1] << std::endl;
		
		// mpz_class zeckSum = 0;
		// // find closest fib and pass to _getZeck()
		// uint32_t fibIndex = 0;
		// for ( mpz_class i = 1; i < argMax; i++ ) {
		// 	if ( i > 1 && i == _fibs[fibIndex+1] ) {
		// 		fibIndex++; // i is fib so increase index
		// 	} 
		// 
		// 	// if i is a fib, zeck is 1, else find zeck
		// 	mpz_class zeck = (i == _fibs[fibIndex]) ? 1 : _getZeck(i, fibIndex);
		// 
		// 	zeckSum += zeck;
		// 	// if ( argMax > 1000000000 && i % 1000000 == 0 ) {
		// 		if ( zeck == 1 ) std::cout << std::endl;
		// 		std::cout << i << "\tz: " << zeck << std::endl;
		// 	// }
		// }
		// std::cout << "Sum of Zeckendorf numbers <" << argMax << ": " << zeckSum << std::endl;
		
		mpz_class zeckTotal = 2, zeckRunning = 1, zNum = 1;
		uint32_t fibIndex = _fibs.size() - 2; // second to last fib
		// std::cout << "fibIndex: " << fibIndex << std::endl;
		for ( mpz_class i = _fibs[fibIndex] + 1; i < _fibs[fibIndex+1]; i++ ) {
			mpz_class zeck = _getZeck(i, fibIndex);
			// std::cout << "zeck: " << zeck << std::endl;
			zeckRunning += zeck;
			zNum++;
			for ( uint32_t k = 3; k < fibIndex+1; k++ ) {
				if ( zNum == _fibs[k] || zNum == argMax - _fibs[fibIndex+1] ) {
					zeckTotal += zeckRunning;
					std::cout << "i: " << i << " \tzR: " << zeckRunning;
					std::cout << "\tzN: " << zNum;
					std::cout << "\tk: " << k << std::endl;
					break;
				}
			}
		}
		std::cout << "Sum of Zeckendorf numbers: " << zeckTotal << std::endl;
	}

private:
	std::vector<mpz_class> _fibs;

	mpz_class _getZeck (mpz_class arg, uint32_t fibIndex) {
		mpz_class number = arg, zeck = 1;
		while (number > 0) {
			number -= _fibs[fibIndex];
			zeck++;
			for ( uint32_t x = fibIndex-2; x >= (uint32_t)0; x--) {
				if ( number == _fibs[x] ) {
					return zeck; 
				}
				else if ( x > 1 && number > _fibs[x] ) {
					fibIndex = x;
					break;
				}
			} 
		}
	}

	
};

int main(int argc, char const* argv[]) {
	// use default argument if none is specified
	mpz_class p297Test = 1000000; // 7894453
	// mpz_class p297Arg = 100000000000000000;
	mpz_class argMax = (argc == 2 ) ? atoi(argv[1]) : p297Test;
	Zeckendorf zeckInst (argMax);

	return 0;
}
