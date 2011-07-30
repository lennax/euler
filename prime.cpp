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
		_primeTable(new uint32_t[n/_blockSize+1]) {
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
		if (isPrime) { 
			std::cout << "is prime" << std::endl;
			std::cout << "blockSize: " << _blockSize << std::endl;
			std::cout << "i % blockSize: " << (i % _blockSize) << std::endl;
			std::cout << "left shift: " << std::bitset<32>(1 << (i % _blockSize)) << std::endl;
			std::cout << "rhs: " << std::bitset<32>(~(1 << (i % _blockSize))) << std::endl;
			std::cout << "result: " << std::bitset<32>(_primeTable[i/_blockSize] & ~(1 << (i % _blockSize))) << std::endl;
			_primeTable[i/_blockSize] &= ~(1 << (i % _blockSize));
		} else { 
			std::cout << "is not prime" << std::endl;
			std::cout << "rhs: " << (1 << (i % _blockSize)) << std::endl;
			_primeTable[i/_blockSize] |= 1 << (i % _blockSize);	
		}
		//_primeTable[i/_blockSize] = 3;
		std::cout << "block after: " << std::bitset<32>(_primeTable[i/_blockSize]) << std::endl;
	}

	bool getPrime(uint32_t i) {
		// if test for bit is true, a non-zero power of 2 
		// will be returned which will be cast to true
		// FIXME: right half probably wrong
		return bool(_primeTable[i/_blockSize] & (1 << (i % _blockSize)));	
	}

	void testStorage(uint32_t i) {
		std::cout << "Initial value of " << 
			i <<  ": " << getPrime(1) << std::endl;
		setPrime(1,false);
		std::cout << "Set " << i << " to composite. New value: " << 
			getPrime(1) << std::endl;
	}

private:
	// attributes
	const uint32_t _n;
	uint32_t * _primeTable; // alu typically atleast 32 bits
	static const uint16_t _blockSize;
};
const uint16_t PrimeFinder::_blockSize = 8*sizeof(*_primeTable); // must match _primeTable type

int main (int argc, char const* argv[])
{
	PrimeFinder primeFinderInstance(1000000);
	return 0;
}
