#include <iostream>
#include <gmpxx.h>
#include "utilities.hpp"

// because it's sequential, I have to 
// * find the maxFib
// * find the zeckendorf representation
// * sum the zeckendorf representation
// within the same loop

mpz_class fibs[8] = {1,2,3,5,8,13,21,34};

int getZeck (mpz_class i, int fibIndex, bool recurse) {
	static int zeck = 1;
	if ( !recurse ) zeck = 1;
	mpz_class number = i;

	if ( zeck == 1 && number == fibs[fibIndex] ) {
		std::cout << "fib z: " << zeck << std::endl;
		return zeck;
	}
	while ( number > 3 ) {
		number -= fibs[fibIndex];
		//std::cout << fibs[fibIndex] << "\t";
		zeck++;
		for ( int x = fibIndex-2; x>-1; x-- ) {
			if ( number == fibs[x] ) {
				std::cout << "z: " << zeck << std::endl;
				return zeck; 
			}
			else if ( x > 2 && number > fibs[x] ) {
				getZeck( number, x, true );
			}
		}
	}
}

int main () {
	int fibIndex = 0;
	mpz_class argMax = 35; 
	for ( mpz_class i = 1; i < argMax; i++ ) {
		//mpz_class maxFib;

		if ( i == 1 ) {
			continue;	// 1 is fibIndex 0 and zeck 1
		}
		else if ( i == fibs[fibIndex+1] ) {
			fibIndex++; // i is fib so increase index
		} 
		//else if ( i > fibs[fibIndex] && i < fibs[fibIndex+1] ) {
			// i is not fib, so don't increase index
			// do nothing?! 
		//}
		
		//maxFib = fibs[fibIndex]; 

		std::cout << "i: " << i << "\t";
	   	getZeck(i, fibIndex, 0);
	}
}
