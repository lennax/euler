#include <iostream>
#include <gmpxx.h> // for mpz_class 
// #include <inttypes.h>
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
		
		// for (int k=0; k <_fibs.size(); k++) {
		// 	std::cout << _fibs[k] << std::endl;
		// }

		mpz_class zeckSum = 0;
		// find closest fib and pass to _getZeck()
		int fibIndex = 0;
		for ( mpz_class i = 1; i < argMax; i++ ) {
			if ( i > 1 && i == _fibs[fibIndex+1] ) {
				fibIndex++; // i is fib so increase index
			} 
			//else if ( i > _fibs[fibIndex] && i < _fibs[fibIndex+1] ) {
				// do nothing?! 
			//}

			// std::cout << "i: " << i << "\t";

			// if i is a fib, zeck is 1, else find zeck
			int zeck = (i == _fibs[fibIndex]) ? 1 : _getZeck(i, fibIndex);

			// if ( zeck == 1 ) std::cout << "z: 1" << std::endl;

			// std::cout << "i: " << i << "\tfi: " << fibIndex << "\tz: " << zeck << std::endl;
			zeckSum += zeck;
		}

		// std::cout << "Sum of Zeckendorf numbers 0<n<" << argMax << ": ";
		// 	std::cout << zeckSum << std::endl;		
			
		// std::cout << _fibs.size() << std::endl;
		std::cout << _getZeck(12, 4) << std::endl;
		
	}

private:
	std::vector<mpz_class> _fibs;

	int _getZeck (mpz_class i, int fibIndex) {
		_getZeckRecursive(i, fibIndex, 1);
	}

	int _getZeckRecursive (mpz_class i, int fibIndex, int zeck) {
		// static int zeck = 1;
		// if ( !recurse ) zeck = 1;
		mpz_class number = i;

		number -= _fibs[fibIndex];
		//std::cout << _fibs[fibIndex] << "\t";
		zeck++;
		for ( int x = fibIndex-2; x>-1; x-- ) {
			if ( number == _fibs[x] ) {
				// std::cout << "z: " << zeck << std::endl;
				return zeck; 
			}
			else if ( x > 1 && number > _fibs[x] ) {
				_getZeckRecursive( number, x, zeck );
			}
		}
	}
	
};

int main(int argc, char const* argv[]) {
	// use default argument if none is specified
	mpz_class argMax = (argc == 2 ) ? atoi(argv[1]) : 10000;
	Zeckendorf zeckInst (argMax);

	return 0;
}
