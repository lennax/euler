#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <inttypes.h>
#include <vector>
#include <sstream>
#include <algorithm>

class PathFinder 
{
public:
	PathFinder () {
		using namespace std;
		cout << "filename: " << endl;
		std::string fileName;
		cin >> fileName;
		readFile(fileName);
		cout << "Original triangle:" << endl;
		printTriangle();	
		uint32_t sum = getSum();
		cout << "L triangle:" << endl;
		printTriangle();
		cout << "sum: " << sum << endl;
	}
private:
	std::vector< std::vector<uint32_t> > _triangle;

	void printTriangle() {
		using namespace std;
		for (int i=0;i<_triangle.size(); i++) {
			for (int j=0;j<i+1;j++) cout << _triangle[i][j] << "\t";
			cout << endl;
		}
	}

	// read file and convert to vector of vectors (2D array)
	void readFile(std::string fileName) {
		using namespace std;
		ifstream file;
		file.open(fileName.c_str());

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
	uint32_t getSum() {
		for (int y=1;y<_triangle.size(); y++) for (int x=0;x<y+1;x++) 
		{
			if (x==0) {
				_triangle[y][x] += _triangle[y-1][x];
				// add x,y to x,y-1
			}	
			else if (x==y) {
				_triangle[y][x] += _triangle[y-1][x-1];
				// add x,y to x-1,y-1
			}
			else {
				_triangle[y][x] += 
					std::max(_triangle[y-1][x], _triangle[y-1][x-1]);
				// add x,y to max((x,y-1), (x-1,y-1))
			}
		}
		uint32_t sum = 0;
		for (int i = 0; i < _triangle.size(); i++) {
			uint32_t current = _triangle[_triangle.size()-1][i];
			if (current > sum) sum = current;
		}
		return sum;
	}

};

int main (int argc, char const* argv[])
{
	PathFinder test;

	return 0;
}

