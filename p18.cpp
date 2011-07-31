#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <inttypes.h>
#include <vector>
#include <sstream>

class PathFinder 
{
public:
	PathFinder () {
		using namespace std;
		readFile2();
		cout << "triangle: " << endl;
		for (int i=0;i<_triangle.size(); i++) {
			for (int j=0;j<i+1;j++) cout << _triangle[i][j] << "\t";
			cout << endl;
		}
	}
private:
	std::vector< std::vector<uint32_t> > _triangle;
	void readFile() {
		// import triangle and convert to 2D array
		std::string line;
		std::ifstream file; 
		file.open ("triangle4.txt");
		if (file.is_open()) {
			std::cout << "File opened" << std::endl;
			while (file.good()) {
				std::cout << "Line good" << std::endl;
				getline(file,line);
				std::cout << line << std::endl;
			}
			file.close();
		}
		else std::cout << "Unable to open file" << std::endl;
	}

	void readFile2() {
		using namespace std;
		ifstream file;
		file.open("triangle4.txt");

		if(!file.is_open()) {
			cout << "File not open" << endl;
		}
		string line;

		while (!getline(file,line,'\n').eof()) {
			istringstream reader(line);

			vector< uint32_t > lineData;

			string::const_iterator i = line.begin();

			while (!reader.eof()) {
				uint32_t val;
				reader >> val;

				if(reader.fail())
					break;

				lineData.push_back(val);
			}

			_triangle.push_back(lineData);
		}
		file.close();
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

