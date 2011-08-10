#include <iostream> // for cout, endl
// #include <algorithm>
#include <math.h> // for sqrt(), floor(), pow()
#include <inttypes.h> // for uint32_t
#include <string> // for string
#include "utilities.hpp" // for itoa()
#include <stdlib.h> // for atoi()

// find first fibonacci number with 1000 digits

// log_2 ( 10^1000 )
// = 1000 * log_2 (10) 
// = 1000 * 3.3219

int main(int argc, char const* argv[]) {
	double phi = (1+sqrt(5))/2;
	
	// compute n and n-1, then recurse
	int rowCount = 0;
	long double prev = 0, cur = 0, temp = 0;
	for (int seed = 1; seed < 21; seed++) {
		if (rowCount == 0 ) {
			cur = floor( (pow(phi,seed) - pow(1-phi,seed)) / sqrt(5) );
			int p_seed = seed-1;
			prev = floor( (pow(phi,p_seed) - pow(1-phi,p_seed)) / sqrt(5) );
		} 
		else { // if prev = 1; cur = 2
			temp = cur; // temp = 2
			cur += prev; // 2+1 = 3
			prev = temp; // prev = 2
			
		}
		if ( seed % 1 == 0 ) 
			std::cout << seed << "\t" << cur << std::endl;
	}
	
	// fully computed
	
	// uint32_t maxDigits = 0;
	// for (int seed = 0; seed < 200; seed++) {
	// 	double fib = floor( (pow(phi,seed) - pow(1-phi,seed)) / sqrt(5) );
	// 	char fibString[33];
	// 	itoa(fib, fibString, 10);
	// 	if ( seed % 10 == 0 )
	// 		std::cout << seed << "\t" << fib << "\t" << strlen(fibString) << std::endl;
	// 		
	// 	if ( strlen(fibString) > maxDigits ) 
	// 		maxDigits = strlen(fibString);
	// 		
	// 	if ( strlen(fibString) == 1000 ) {
	// 		std::cout << "Term " << seed << " has 1000 digits." << std::endl;
	// 		exit(0);
	// 	}
	// }
	// std::cout << "Max digits: " << maxDigits << std::endl;
	
	
	// interactive
	
	// uint32_t rowCount = 0;
	// if ( argc != 2) { 
	// 	std::cout << "Usage: " << argv[0] << " n" << std::endl;
	// 	exit(1);
	// }
	// int seed = atoi(argv[2]);
	// char input[256];
	// printf ("Enter a number: ");
	// fgets (input, 256, stdin);
	// int seed = atoi (input);
	// double fib = floor( (pow(phi,seed) - pow(1-phi,seed)) / sqrt(5) );
	// std::cout << fib << std::endl;
	
	return 0;
}