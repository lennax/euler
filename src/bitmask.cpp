#include <iostream> // for std::cout etc.
#include <vector>
#include <inttypes.h> // for uint32_t
#include <cstdlib> // for atoi()

class Bitmask
{
public:
	// constructor
	Bitmask(uint32_t n): 
	_n(0), 
	_size(n) {

	}

	// methods
	void setBit(uint32_t bit, bool set = true) {
		if (bit > _size) {
			std::cerr << "Bit is larger than allowed" << std::endl;
			std::cerr << "Max size is " << _size << std::endl;
			return;
		}
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
		for (uint32_t bit = 0; bit < _size+1; bit++) {
			if (getBit(bit)) {
				bitlist.push_back(bit);
			}
		}
		return bitlist;
	}

private:
	// attributes
	uint32_t _n;
	uint8_t _size;

};

int main(int argc, char const* argv[]) {
	uint8_t default_size = 21;
	uint8_t size = (argc == 2) ? atoi(argv[1]) : default_size;
	if (size > 30) {
		std::cerr << "Error: Size must be less than 31" << std::endl;
		exit(1);
	}

	uint8_t combat_mage[] = { 2, 4, 15, 17, 18, 19, 20 };

	Bitmask bitmaskInstance(size);

	// test cases
	//bitmaskInstance.setBit(3);
//	std::cout << bitmaskInstance.getBit(2) << std::endl;
//	std::cout << bitmaskInstance.getBit(3) << std::endl;


	//bitmaskInstance.setBit(5);
	//bitmaskInstance.setBit(15);
	//bitmaskInstance.setBit(16);
	//bitmaskInstance.setBit(size);
	//std::cout << bitmaskInstance.getBit(15) << std::endl << std::endl;
	for ( uint8_t i = 0; i < 7; i++ ) {
		bitmaskInstance.setBit(combat_mage[i]);
	}
	std::vector<uint32_t> setlist = bitmaskInstance.listBits();
	for (uint32_t i = 0; i < setlist.size(); i++) {
		std::cout << setlist[i] << std::endl;
	}
}
