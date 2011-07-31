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
		_primeTable(new uint8_t[n/_blockSize+1]) {
			testStorage(1);
			testStorage(2);
		}

	// deconstructor, cleanup
	~PrimeFinder() {
		delete [] _primeTable;
		_primeTable = NULL;
	}

	// methods
	void setPrime(uint32_t i, bool isPrime) {
		std::cout << "block before: " << std::bitset<8>(_primeTable[i/_blockSize]) << std::endl;
		if (isPrime) { 
			_primeTable[i/_blockSize] &= ~(1 << (i % _blockSize));
		} else { 
			_primeTable[i/_blockSize] |= 1 << (i % _blockSize);	
		}
		std::cout << "block after: " << std::bitset<8>(_primeTable[i/_blockSize]) << std::endl;
	}

	bool getPrime(uint32_t i) {
		// if test for bit is true, a non-zero power of 2 
		// will be returned which will be cast to true
		// FIXME: right half probably wrong
		return bool(_primeTable[i/_blockSize] & (1 << (i % _blockSize)));	
	}

	void testStorage(uint32_t i) {
		std::cout << "\ninitial value of " << 
			i <<  ": " << getPrime(i) << std::endl;
		setPrime(i,false);
		std::cout << "set " << i << " to composite, new value: " << 
			getPrime(i) << std::endl;
	}

private:
	// attributes
	const uint32_t _n;
	uint8_t * _primeTable; // the smaller the window the better
	static const uint16_t _blockSize;
};
const uint16_t PrimeFinder::_blockSize = 8*sizeof(*_primeTable); // must match _primeTable type

int main (int argc, char const* argv[])
{
	PrimeFinder primeFinderInstance(1000000);
	return 0;
}
