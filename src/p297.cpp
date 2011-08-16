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
		for ( mpz_class i = 2; i < 100; i++ ) {
			mpz_class fib = smallFib(i.get_ui());
			if ( fib <= argMax ) {
				_fibs.push_back(fib);
			} 
			else break;	
		}
		
		//for (int k=0; k <_fibs.size(); k++) {
			//std::cout << _fibs[k] << std::endl;
		//}

		mpz_class zeckSum = 0;
		// find closest fib and pass to _getZeck()
		uint32_t fibIndex = 0;
		for ( mpz_class i = 1; i < argMax+1; i++ ) {
			if ( i > 1 && i == _fibs[fibIndex+1] ) {
				fibIndex++; // i is fib so increase index
			} 
			//else if ( i > _fibs[fibIndex] && i < _fibs[fibIndex+1] ) {
				// do nothing?! 
			//}

			// std::cout << "i: " << i << "\t";

			// if i is a fib, zeck is 1, else find zeck

		//mpz_class zeck = (i == _fibs[fibIndex]) ? 1 : _getZeck(i, fibIndex);

			//if ( zeck == 1 ) std::cout << i << " z: 1" << std::endl;

			//std::cout << "i: " << i << "\tz: " << zeck << std::endl;
		//zeckSum += zeck;
		}

		// std::cout << "Sum of Zeckendorf numbers 0<n<" << argMax << ": ";
		// 	std::cout << zeckSum << std::endl;		
			
		// std::cout << _fibs.size() << std::endl;

		//mpz_class zeckMpz = _getZeck(12,4);
		//int zeckInt = zeckMpz.get_si();
		//std::cout << zeckInt << std::endl;
		std::cout << "(12,4)" << _getZeck(12,4) << std::endl;
	}

private:
	std::vector<mpz_class> _fibs;

	mpz_class _getZeck (mpz_class arg, uint32_t fIndex) {
		//std::cout << arg << " ";
		return _getZeckRecursive(arg, fIndex, 1);
	}

	mpz_class _getZeckRecursive (mpz_class j, uint32_t fIndex, mpz_class zeck) {
		// static int zeck = 1;
		// if ( !recurse ) zeck = 1;
		mpz_class number = j;

		number -= _fibs[fIndex];
		//std::cout << _fibs[fibIndex] << "\t";
		zeck++;

		if ( number > (mpz_class)0 && number < (mpz_class)4 ) {
			//zeck++;
			return zeck;
		}
		//std::cout << number << "\t" << _fibs[fIndex] << "\t";

		std::cout << "number: " << number << std::endl;
		for ( uint32_t x = fIndex-2; x >= (uint32_t)0; x-- ) {
			std::cout << "fIndex: " << fIndex << std::endl;
			std::cout << "x: " << x << std::endl;
			std::cout << "_fibs[x]: " << _fibs[x] << std::endl;
			if ( (int)number.get_ui() == (int)_fibs[x].get_ui() ) {
				//std::cout << "z: " << zeck << std::endl;
				return zeck; 
			}
			else if ( x > 1 && (int)number.get_ui() > (int)_fibs[x].get_ui() ) {
				std::cout << "Recursing: " << number << " ";
				std::cout << x << " " << zeck << std::endl;
				_getZeckRecursive( number, x, zeck );
			}
		}
		std::cout << "did not return" << std::endl;
		//return zeck;
	}
	
};

int main(int argc, char const* argv[]) {
	// use default argument if none is specified
	mpz_class argMax = (argc == 2 ) ? atoi(argv[1]) : 10000;
	Zeckendorf zeckInst (argMax);

	return 0;
}
