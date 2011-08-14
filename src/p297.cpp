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
	Zeckendorf(mpz_class argMin, mpz_class argMax)
	{
		// construct vector 
		for ( mpz_class i=argMin; i<argMax+1; i++ ) {
			mpz_class fib = smallFib(i.get_ui());
			if ( fib <= argMax ) {
				_fibs.push_back(fib);
				// std::cout << fib << std::endl;
			} 
			else break;	
		}
		// std::cout << "Constructed vector <= " << argMax << std::endl;
		
		// std::cout << _fibs.size() << std::endl;
		std::cout << _zeckSum(argMin, argMax) << std::endl;;
		
	}

private:
	mpz_class _zeckSum(mpz_class argMin, mpz_class argMax) {
		mpz_class zeckSum = 0;
		for ( mpz_class i = argMin; i < argMax; i++ ) {
			// std::cout << i << ":\t";
			zeckSum += _zeck(i);
		}
		return zeckSum;
	}

	mpz_class _maxFib(mpz_class arg) {
		for ( mpz_class search = arg; search > 0; search-- ) {
			if (std::binary_search (_fibs.begin(), _fibs.end(), search)) {
				// std::cout << "Found " << search << std::endl;
				return search;
			}
		}
		std::cout << arg << " not found" << std::endl;
		exit(1);
	}
	
	mpz_class _zeck(mpz_class arg) {
		mpz_class zeck = 1;
		mpz_class number = arg;
		while (number >= 3) {
			mpz_class piece = _maxFib(number);
			// std::cout << piece << " ";
			if (piece == number) {
				// std::cout << "\nzeck == " << zeck << std::endl;
				return zeck;
			}
			number -= piece;
			zeck++;
			// std::cout << number << "\t" << piece << "\t" <<  zeck << std::endl;
		}
		// std::cout << "\nzeck should be " << zeck << std::endl; 
		return zeck;
	}
	
	std::vector<mpz_class> _fibs;
};

//uint32_t zeckendorf (double number) {
	//uint32_t zeck = 1;
	//while (number > 3) {
		//mpf_class zeckPiece = fibCeil(number);
		//if ( zeckPiece == number ) {
			//std::cout << number << " is fib" << std::endl;
			//return 1;
		//}
		//std::cout << number << "\t" << zeckPiece << "\t" <<  zeck << std::endl;
		//number -= zeckPiece.get_d();
		//zeck++;
	//}

	//return 1;
//}


int main(int argc, char const* argv[]) {
	// uint32_t arg = 85;
	if (argc==2) {
		mpz_class argMax = atoi(argv[1]);
		Zeckendorf zeckInst(1, argMax);
	} else {
		// mpz_class argMax = 10000000000000000000;
		mpz_class argMax = 10000;
		
		Zeckendorf zeckInst (1, argMax);
	}
	//zeckendorf(arg);
	
	// std::vector<mpz_class> fibs = fibVector(arg);
	//for ( uint32_t i=0; i<fibs.size(); i++ ) {
		//std::cout << fibs[i] << std::endl;
	//}
	
	//mpz_class search = 55;
	
	// std::cout << maxFib(arg) << std::endl;
	
	return 0;
}
