#include <iostream>

// n² + an + b, where |a| < 1000 and |b| <  1000
class PrimeQuadratic 
{
public:
	PrimeQuadratic() {}

private:
	void crunch() {
		for (int a=-999;a<1000;a++) for (int b=-999;b<1000;b++) {
			for (int n=0;n<300;n++) {
				int current = n*n+a*n+b;
			//	if (!getPrime(current)) 
			//		break;
			}
		}
	}
};

int main (int argc, char const* argv[])
{
	PrimeQuadratic primeQuadraticInstance();
	return 0;
}


