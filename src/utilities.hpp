/*******************************************************
* itoa code contributed by Chris Takahashi,            *
* ctakahashi (at) users (dot) sourceforge (dot) net.   *
* See stdlib.h for licence.                            *
* $Date: 2005/08/31 11:39:47 $                         *
*******************************************************/

#ifndef _UTILITIES_HPP
#define _UTILITIES_HPP

#include <stdlib.h>
#include <inttypes.h> // fib() and pow(): for uint32_t
#include <gmpxx.h> // fib() and pow(): for mpf_class etc
#include <math.h> // fib(): for sqrt()

extern "C" {

	// convert integer to c string
	char *itoa(int num, char *str, int radix);

}
 
	// compute nth fibonacci term
	mpf_class fib(uint32_t n);

	// overload pow() for mpf_class
	mpf_class pow(mpf_class base, uint32_t exp);
	
	// return exponent (0.x ^ exp) of an mpf_class
	mp_exp_t getExp(mpf_class f_class);

#endif // _UTILITIES_HPP

