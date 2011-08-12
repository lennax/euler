#include "p25.hpp" 

// find first fibonacci number with 1000 digits

// compute nth fibonacci term
mpf_class fib(uint32_t n) {
	mpf_class fib;
	mpf_class phi = (1+sqrt(5))/2;
	fib = floor( (pow(phi,n) - pow(1-phi,n) ) / sqrt(5) );
	return fib;
}

// overload pow() for mpf_class
mpf_class pow(mpf_class base, uint32_t exp) {
	mpf_class result;
	mpf_ptr resultPtr = result.get_mpf_t();
	mpf_ptr basePtr = base.get_mpf_t();
	mpf_pow_ui(resultPtr, basePtr, exp);
	return result; 
}

// return exponent
mp_exp_t getExp(mpf_class f_class) {
	mpf_ptr fl = f_class.get_mpf_t();
	char * str;
	mp_exp_t exp;
	int base = 10;
	size_t n_digits = 2;
	mpf_get_str(str, &exp, base, n_digits, fl);
	return exp;
}

int main(int argc, char const* argv[]) {
	mpf_class prev, cur, temp;
	int rowNum = 0;
	mp_exp_t maxExp;
	for (uint32_t seed = 0; seed < 5000; seed++) {
		if (rowNum == 0) {
			cur = fib(seed);
			prev = fib(seed-1);
		} else {
			temp = cur; 
			cur += prev;
			prev = temp;
		}
		//if ( seed % 10 == 0 ) {
			//mp_exp_t curExp = getExp(cur);
			//std::cout << seed << "\t" << cur << "\t" << curExp << std::endl;
		//}
		mp_exp_t curExp = getExp(cur);
		if (curExp > maxExp) {
			maxExp = curExp;
		}
		if (curExp >= 1000) {
			std::cout << "Term with >1000 digits: " << seed << std::endl;
			break;
		}
	}
	std::cout << "max exp: " << maxExp << std::endl;

		return 0;
}
