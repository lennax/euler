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
		// construct vector (99th term is well over 10^17)
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

		mpz_class zeckTotal = 2, zeckRunning = 1, zNum = 1;
		uint32_t kNum = 3;
		bool rAdded = false;
		uint32_t fibIndex = _fibs.size() - 2; // second to last fib
		// std::cout << "fibIndex: " << fibIndex << std::endl;
		for ( mpz_class i = _fibs[fibIndex] + 1; i < _fibs[fibIndex+1]; i++ ) {
			mpz_class zeck = _getZeck(i, fibIndex);
			// std::cout << "zeck: " << zeck << std::endl;
			zeckRunning += zeck;
			zNum++;

			mpz_class r = argMax - _fibs[fibIndex+1];
			// only need to add once for each fib
			if ( zNum == _fibs[kNum] ) {
				zeckTotal += zeckRunning;
				if (kNum < fibIndex) kNum++;
			}
			if ( rAdded == false && zNum == r ) {
				zeckTotal += zeckRunning;
				rAdded = true;
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
