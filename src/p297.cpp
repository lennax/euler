#include <iostream>
#include <gmpxx.h> 
#include <inttypes.h>
#include "utilities.cpp"
#include <vector>

std::vector<double> fibVector(uint32_t max_n) {
	std::vector<double> fibs;
	//fibs.push_back(0);
	if ( max_n < 1482 ) for ( uint32_t i=2; i<max_n; i++ ) {
		double fib = smallFib(i);
		if ( int(fib) <= max_n ) {
			fibs.push_back(smallFib(i));
		} else {
			return fibs;	
		}
	}
	return fibs;
}	


//mpf_class fibCeil (double number) {
	//mpf_class fib, ceil;
	//for (uint32_t i=0; i<number; i++) {
		//fib = getFib(i);
		//if ( fib < number ) {
			//ceil = fib;
		//} else if ( fib == number ) {
			//return fib;
		//} else {
			//break;
		//}
	//}
	//return ceil;
//}

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

int main() {
	uint32_t arg = 85;
	//zeckendorf(arg);
	//std::cout << smallFib(2) << std::endl;
	//std::cout << fibCeil(100) << std::endl;	
	
	std::vector<double> fibs = fibVector(arg);
	//for ( uint32_t i=0; i<fibs.size(); i++ ) {
		//std::cout << fibs[i] << std::endl;
	//}
	uint32_t middle = floor(fibs.size()/2);
	if ( fibs[middle] > arg ) {

	} else if ( fibs[middle] == arg ) {

	} else {

	}

	return 0;
}
