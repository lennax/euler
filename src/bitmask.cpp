#include <iostream> // for std::cout etc.
#include <vector>
#include <inttypes.h> // for uint32_t

class Bitmask
{
public:
	// constructor
	Bitmask(uint32_t n, uint32_t max): 
	_n(1 << n),
	_max(max) {

	}

	// methods
	void setBit(uint32_t bit, bool set = true) {
		if (set) {
			_n |= 1 << bit;
		}
		else {
			_n &= ~(1 << bit);
		}
	}

	bool getBit(uint32_t bit) {
		bool check = _n & 1 << bit;
		return check;	
	}

	std::vector<uint32_t> listBits() {
		std::vector<uint32_t> bitlist;
		for (uint32_t bit = 0; bit < _max+1; bit++) {
			if (getBit(bit)) {
				bitlist.push_back(bit);
			}
		}
		return bitlist;
	}

private:
	// attributes
	uint32_t _n;
	uint32_t _max;

};

int main(int argc, char const* argv[]) {
	uint8_t size = 21;
	if (size > 30) {
		std::cerr << "Error: Size must be less than 31" << std::endl;
		exit(1);
	}

	Bitmask bitmaskInstance(size,size);

	// test cases
	bitmaskInstance.setBit(3);
//	std::cout << bitmaskInstance.getBit(2) << std::endl;
//	std::cout << bitmaskInstance.getBit(3) << std::endl;


	bitmaskInstance.setBit(5);
	bitmaskInstance.setBit(15);
	bitmaskInstance.setBit(16);
	std::cout << bitmaskInstance.getBit(15) << std::endl << std::endl;
	std::vector<uint32_t> setlist = bitmaskInstance.listBits();
	for (uint32_t i = 0; i < setlist.size(); i++) {
		std::cout << setlist[i] << std::endl;
	}
}
