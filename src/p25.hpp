#include <iostream> // for cout, endl
#include <math.h> // for sqrt() ( pow() and floor() are overloaded
#include <inttypes.h> // for uint32_t
#include <gmpxx.h> // for mpf_class etc

// find first fibonacci number with 1000 digits

// overload pow() for mpf_class
mpf_class pow(mpf_class base, uint32_t exp); 

// compute nth fibonacci term
mpf_class fib(uint32_t n);

// return exponent
mp_exp_t getExp(mpf_class f_class); 
