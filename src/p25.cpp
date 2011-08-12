#include <iostream> // for cout, endl
#include <inttypes.h> // for uint32_t
#include <gmpxx.h> // for mpf_class etc
#include "utilities.hpp" // for mpf_class pow() and fib()

// find first fibonacci number with 1000 digits

int main(int argc, char const* argv[]) {
	mpf_class prev, cur, temp;
	int rowNum = 0;
	mp_exp_t maxExp;
	for (uint32_t seed = 4500; seed < 5000; seed++) {
		if ( seed == 0) {
			continue; // F(0) and F(1) are both 0 
		}
		if (rowNum == 0) {
			cur = fib(seed);
			prev = fib(seed-1);
			rowNum++;
		} else {
			temp = cur; 
			cur += prev;
			prev = temp;
		}
		mp_exp_t curExp = getExp(cur);
		//if ( seed % 10 == 0 ) {
			//std::cout << seed << "\t" << cur << "\t" << curExp << std::endl;
		//}
		if (curExp >= 1000) {
			std::cout << "Term with >1000 digits: " << seed << std::endl;
			exit(0);
		}
		else if (curExp > maxExp) {
			maxExp = curExp;
		} 
	}
	std::cout << "max exp: " << maxExp << std::endl;

		return 0;
}
