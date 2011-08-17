#include <iostream>
#include <gmpxx.h>
#include "utilities.hpp"

// because it's sequential, I have to 
// * find the maxFib
// * find the zeckendorf representation
// * sum the zeckendorf representation
// within the same loop

mpz_class fibs[8] = {1,2,3,5,8,13,21,34};

mpz_class lek () {
	static const mpf_class phi = (1+sqrt(5))/2;
	// mpz_class bigNum = 100000000000000000;
	mpz_class smallNum = 20;
	mpz_class avg = smallNum / ( phi * phi + 1 );
	return avg;
	
}

int _getZeck (mpz_class i, int fibIndex, bool recurse = false) {
	static int zeck = 1;
	if ( !recurse ) zeck = 1;
	mpz_class number = i;

	number -= fibs[fibIndex];
	//std::cout << fibs[fibIndex] << "\t";
	zeck++;
	for ( int x = fibIndex-2; x>-1; x-- ) {
		if ( number == fibs[x] ) {
			std::cout << "z: " << zeck << std::endl;
			return zeck; 
		}
		else if ( x > 1 && number > fibs[x] ) {
			_getZeck( number, x, true );
		}
	}
}

int main () {
	int fibIndex = 0;
	mpz_class argMax = 35; 
	for ( mpz_class i = 1; i < argMax; i++ ) {
		if ( i > 1 && i == fibs[fibIndex+1] ) {
			fibIndex++; // i is fib so increase index
		} 
		//else if ( i > fibs[fibIndex] && i < fibs[fibIndex+1] ) {
			// do nothing?! 
		//}
		
		std::cout << "i: " << i << "\t";
		
		// if i is a fib, zeck is 1, else find zeck
		int zeck = (i == fibs[fibIndex]) ? 1 : _getZeck(i, fibIndex);
		
		if ( zeck == 1 ) std::cout << "z: 1" << std::endl;
		

	}
		std::cout << "lek: " << lek() << std::endl;
}
