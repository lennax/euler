// If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, 
// there are exactly three solutions for p = 120.
// 
// {20,48,52}, {24,45,51}, {30,40,50}
// 
// For which value of p ≤ 1000, is the number of solutions maximised?

// int a, b, c, p;
// a + b + c = p 
// a^2 + b^2 = c^2 
// for known a and p
// b = p - a - c
// a^2 + (p-a - c)^2 = c^2 

// (k - c)^2
// k^2 - 2kc + c^2
// a^2 + (p-a)^2 - 2(p-a)*c + c^2 = c^2
// a^2 + (p-a)^2 - 2(p-a)*c = 0
// a^2 + (p-a)^2 = 2(p-a)*c
// c = (a^2 + (p-a)^2)/2(p-a)
// c = (p^2 - 2ap + 2a^2)/2(p-a))

#include <iostream> // for cout, endl
#include <math.h> // for pow()

bool checkInt(double arg) {
	double difference = arg - int(arg);
	if ( difference < 0.001 ) {
		return true;
	}
	return false;
}

int main() {
	int max = 1000;
	std::cout << "a\tb\tc" << std::endl;
	int sidesMax = 0;
	int bestP = 0;
	for ( int p = 7; p < max+1; p++ ) {
		std::cout << "p = " << p << std::endl;
		int sidesCount = 0;
		for ( int a = 1; a < p/3.5; a++ ) {
			double c = (pow(a,2) + pow(p-a,2))/(2*(p-a));
			double b = p - a - c;
			if ( checkInt(b) && checkInt(c) ) {
				std::cout << a << "\t" << b << "\t" << c << std::endl;
				sidesCount++;
				if ( sidesCount > sidesMax ) {
					sidesMax = sidesCount;
					bestP = p;
				}
			}
		}
	}
	std::cout << "p = " << bestP << " has " << sidesMax << " solutions." << std::endl;
}