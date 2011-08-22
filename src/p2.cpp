#include <iostream>
#include <inttypes.h>
#include "utilities.hpp"
#include <gmpxx.h>

// find sum of even Fibonacci terms >= 4M

int main() {
	mpf_class fib;
	uint32_t total;
	bool complete = false;
	for ( uint32_t n=0; n<100; n++ ) {
		fib = intFib(n);
		//std::cout << "mpf_class: " << fib << std::endl;
		if ( fib.fits_uint_p()) {
			unsigned long fib_ui = fib.get_ui();
			// FIXME this turns F(2) = 1 into 0
			//std::cout << "ulong: " << fib_ui << std::endl;	
			if ( fib_ui >= 4000000 ) {
				complete = true;
				break;
			}

			if ( fib_ui % 2 == 0 ) {
				total += fib_ui;
			}
		}
	}
	if ( complete ) {
		std::cout << "Total: " << total << std::endl;
	} else {
		std::cout << "Not complete, increase range" << std::endl;
	}
	return 0;
}
