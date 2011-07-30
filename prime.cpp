#include <inttypes.h>
#include <cstdio>
#include <iostream>
#include <bitset>

class PrimeFinder
{
public:
	// constructor, using raii (resource acquisition is initialization)
	PrimeFinder(uint32_t n) : 
		_n(n), 
		_primeTable(new uint32_t[n/32+1]) {
			std::cout << "table 0: " << _primeTable[0] << std::endl;
			std::cout << "table 1: " << _primeTable[1] << std::endl;
			testStorage(1);
			testStorage(2);
		}

	// deconstructor, cleanup
	~PrimeFinder() {
		delete [] _primeTable;
		_primeTable = NULL;
		std::cout << "I just deallocated a huge array" << std::endl;
	}

	// methods
	void setPrime(uint32_t i, bool isPrime) {
		std::cout << "block before: " << std::bitset<32>(_primeTable[i/_blockSize]) << std::endl;
		if (~isPrime) { // 0 is prime, so set to 1
			_primeTable[i/_blockSize] |= 1 << ((i-1) % _blockSize);	
		} else { // 0 is prime, set to 0
			_primeTable[i/_blockSize] &= ~(1 << ((i-1) % _blockSize));
		}
		std::cout << "block after: " << std::bitset<32>(_primeTable[i/_blockSize]) << std::endl;
	}

	bool getPrime(uint32_t i) {
		// if test for bit is true, a non-zero power of 2 
		// will be returned which will be cast to true
		// FIXME: right half probably wrong
		return bool(_primeTable[i/_blockSize] & (1 << ((i-1) % _blockSize)));	
	}

	void testStorage(uint32_t i) {
		std::cout << "Initial value of " << 
			i <<  ": " << getPrime(1) << std::endl;
		setPrime(1,true);
		std::cout << "Set " << i << " to prime. New value: " << 
			getPrime(1) << std::endl;
	}

private:
	// attributes
	const uint32_t _n;
	uint32_t * _primeTable; // alu typically atleast 32 bits
	static const uint8_t _blockSize;
};
const uint8_t PrimeFinder::_blockSize = 32; // must match _primeTable type

int main (int argc, char const* argv[])
{
	PrimeFinder primeFinderInstance(1000000);
	return 0;
}
