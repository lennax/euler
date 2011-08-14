#include "utilities.hpp"

/*******************************************************
* itoa code contributed by Chris Takahashi,            *
* ctakahashi (at) users (dot) sourceforge (dot) net.   *
* See stdlib.h for licence.                            *
* $Date: 2005/08/31 11:39:47 $                         *
*******************************************************/

char *itoa(int num, char *str, int radix) {
    char sign = 0;
    char temp[17];  //an int can only be 16 bits long
                    //at radix 2 (binary) the string
                    //is at most 16 + 1 null long.
    int temp_loc = 0;
    int digit;
    int str_loc = 0;

    //save sign for radix 10 conversion
    if (radix == 10 && num < 0) {
        sign = 1;
        num = -num;
    }
    
    //construct a backward string of the number.
    do {
        digit = (unsigned int)num % radix;
        if (digit < 10) 
            temp[temp_loc++] = digit + '0';
        else
            temp[temp_loc++] = digit - 10 + 'A';
        num = (((unsigned int)num) / radix);
    } while ((unsigned int)num > 0);

    //now add the sign for radix 10
    if (radix == 10 && sign) {
        temp[temp_loc] = '-';
    } else {
        temp_loc--;
    }


    //now reverse the string.
    while ( temp_loc >=0 ) {// while there are still chars
        str[str_loc++] = temp[temp_loc--];    
    }
    str[str_loc] = 0; // add null termination.

    return str;
}

// compute nth fibonacci term
//mpf_class getFib(uint32_t n) {
	//mpf_class fib;
	//mpf_class phi = (1+sqrt(5))/2;
	//// this equation is exact, so floor() is dangerous
	//// mpf_class will absorb any flop errors
	//fib = (pow(phi,n) - pow(1-phi,n) ) / sqrt(5);
	//return fib;
//}

mpz_class intFib(const uint32_t n) {
	mpz_class fib; 
	// fib = ( mpf_pow((1+sqrt(5))/2,n) - mpf_pow((1-sqrt(5))/2,n) ) / sqrt(5);
	static const mpf_class phi = (1+sqrt(5))/2;
	// fib = floor ( mpf_pow( phi, n ) / sqrt(5) + 1/2 );
	// fib = mpf_pow (phi, n) / sqrt(5);
	fib = floor ( mpf_pow( phi, n ) / sqrt(5) + 0.5 );
	return fib;
}

//mpz_class mpz_pow(mpz_class base, uint32_t exp) {
	//mpz_class result;
	//mpz_ptr resultPtr = result.get_mpz_t();
	//mpz_ptr basePtr = base.get_mpz_t();
	//mpz_pow_ui(resultPtr, basePtr, exp);
	//return result; 
//}

// compute fibonacci term (n < 1482)
double smallFib(double n) {
	if ( n > 1481 ) {
		std::cerr << "use getFib() for n=" << n << std::endl;
		return(-1);
	}
	double fib;
	double phi = (1+sqrt(5))/2;
	// this equation is exact, so floor() is dangerous
	// mpf_class will absorb any flop errors
	fib = (pow(phi,n) - pow(1-phi,n) ) / sqrt(5);
	return fib;
}

// overload pow() for mpf_class
mpf_class mpf_pow( const mpf_class base, const uint32_t exp) {
	mpf_class result;
	mpf_ptr resultPtr = result.get_mpf_t();
	const mpf_ptr basePtr = (const mpf_ptr) base.get_mpf_t();
	mpf_pow_ui(resultPtr, basePtr, exp);
	return result; 
}

// return exponent (0.x ^ exp) of an mpf_class
mp_exp_t getExp(mpf_class f_class) {
	mp_exp_t exp;
	mpf_ptr fl = f_class.get_mpf_t();
	char * str;
	int base = 10;
	size_t n_digits = 2;
	mpf_get_str(str, &exp, base, n_digits, fl);
	return exp;
}

