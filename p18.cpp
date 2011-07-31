#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

class PathFinder 
{
public:
	PathFinder () {
		readFile();
	}
private:
	void readFile() {
		// import triangle and convert to 2D array
		std::string line;
		std::ifstream triangle; 
		triangle.open ("triangle4.txt");
		if (triangle.is_open()) {
			std::cout << "File opened" << std::endl;
			while (triangle.good()) {
				std::cout << "Line good" << std::endl;
				getline(triangle,line);
				std::cout << line << std::endl;
			}
			triangle.close();
		}
		else std::cout << "Unable to open file" << std::endl;
	}

	void readFile2() {
		std::vector< std::vector< uint32_t > > triangle;
		
	}

	// triangle addition logic
	int getSum() {
		int x;
		int y;
		if (x==0) {
			// add x,y to x,y-1
		}	
		else if (x==y) {
			// add x,y to x-1,y-1
		}
		else {
			// add x,y to max((x,y-1), (x-1,y-1))
		}
	}
};

int main (int argc, char const* argv[])
{
	PathFinder test;

	return 0;
}

