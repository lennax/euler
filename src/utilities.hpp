/*******************************************************
* itoa code contributed by Chris Takahashi,            *
* ctakahashi (at) users (dot) sourceforge (dot) net.   *
* See stdlib.h for licence.                            *
* $Date: 2005/08/31 11:39:47 $                         *
*******************************************************/

#ifndef _UTILITIES_HPP
#define _UTILITIES_HPP

#include <stdlib.h>
#include <iostream> // smallFib(): cerr, endl
#include <inttypes.h> // getFib() and pow(): for uint32_t
#include <gmpxx.h> // getFib() and pow(): for mpf_class etc
#include <math.h> // getFib(): for sqrt()

extern "C" {

	// convert integer to c string
	char *itoa(int num, char *str, int radix);

}

mpz_class intFib(const uint32_t n);

// mpz_class pow(mpz_class base, uint32_t exp);

// compute nth fibonacci term
// mpf_class getFib(uint32_t n);

// compute fibonacci term (n < 1482)
double smallFib(double n);

// overload pow() for mpf_class
mpf_class mpf_pow(const mpf_class base, const uint32_t exp);

// return exponent (0.x ^ exp) of an mpf_class
mp_exp_t getExp(mpf_class f_class);

#endif // _UTILITIES_HPP

