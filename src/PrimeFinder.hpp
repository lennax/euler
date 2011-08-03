#ifndef _PRIMEFINDER_HPP
#define _PRIMEFINDER_HPP

#include <inttypes.h>
#include <cstdio>
#include <iostream>
#include <bitset>

class PrimeFinder
{
public:
	// constructor, using raii (resource acquisition is initialization)
	PrimeFinder(uint32_t n);

	// deconstructor, cleanup
	~PrimeFinder();

	// methods
	void setPrime(uint32_t i, bool isPrime);
	bool getPrime(uint32_t i);
	void testStorage(uint32_t i);

private:
	// attributes
	const uint32_t _n;
	uint8_t * _primeTable; // the smaller the window the better
	static const uint16_t _blockSize;
};

#endif // _PRIMEFINDER_HPP
