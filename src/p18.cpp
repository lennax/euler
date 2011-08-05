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
	PathFinder (const char * fileName) {
		using namespace std;
		//cout << "filename: " << endl;
		//std::string fileName;
		//cin >> fileName;
		readFile(string(fileName));
		cout << getShape() << endl;

		//cout << "Original triangle:" << endl;
		//printMatrix();	
		//uint32_t sum = getSum();
		//cout << "L triangle:" << endl;
		//printMatrix();
		//cout << "sum: " << sum << endl;

	}
private:
	std::vector< std::vector<uint32_t> > _matrix;
	
	// read file and convert to vector of vectors (2D array)
	void readFile(std::string fileName) {
		using namespace std;
		ifstream file;
		file.open(fileName.c_str());

		if(!file.is_open()) {
			cout << "could not open file: " << fileName << endl;
			exit(1);
		}

		string delimTest;
		getline(file,delimTest,'\n'); 
		//cout << delimTest << endl;
		if (delimTest.find(" ") != string::npos) {
			cout << "delim is space" << endl;
		} else if (delimTest.find(",") != string::npos) {
			cout << "delim is comma" << endl;
		} else { 
			cout << "if triangle, is space" << endl;
		}

		file.close();
		file.open(fileName.c_str());

		string line;
		while (!getline(file,line,'\n').eof()) {
			istringstream reader(line);

			vector<uint32_t> lineData;

			//string::const_iterator i = line.begin();

			//while (!reader.eof()) {
				//uint32_t val;
				//reader >> val;

				//if(reader.fail())
					//break;

				//lineData.push_back(val);
			//}

			uint32_t number;
			string number_str;
			char delimiter = ' ';
			while ( getline(reader, number_str, delimiter) 
				  && istringstream( number_str ) >> number)
			{
				lineData.push_back (number);	
			}

			// push vector lineData into vector vector _matrix
			_matrix.push_back(lineData);
		}
		file.close();
	}

	// determine whether matrix is triangle or square
	std::string getShape()
   	{
		// XXX this works
		//std::vector<uint32_t> lastRow = _matrix[_matrix.size()-1]; 
		//int lastRowSize = lastRow.size();
		//std::cout << lastRowSize << std::endl;

		std::cout << "height: " << _matrix.size() << std::endl;

		std::cout << "widths:" << std::endl;

		std::cout << "0th: " << _matrix[0].size() << std::endl;

		std::cout << "nth: " << _matrix[_matrix.size()-1].size() << std::endl;

		return "end getShape";
	}

	void printMatrix() {
		using namespace std;
		for (int i=0;i<_matrix.size(); i++) {
			for (int j=0;j<i+1;j++) cout << _matrix[i][j] << "\t";
			cout << endl;
		}
	}

	// triangle addition logic
	uint32_t getSum() {
		for (int y=1;y<_matrix.size(); y++) for (int x=0;x<y+1;x++) 
		{
			if (x==0) {
				_matrix[y][x] += _matrix[y-1][x];
				// add x,y to x,y-1
			}	
			else if (x==y) {
				_matrix[y][x] += _matrix[y-1][x-1];
				// add x,y to x-1,y-1
			}
			else {
				_matrix[y][x] += 
					std::max(_matrix[y-1][x], _matrix[y-1][x-1]);
				// add x,y to max((x,y-1), (x-1,y-1))
			}
		}
		uint32_t sum = 0;
		for (int i = 0; i < _matrix.size(); i++) {
			uint32_t current = _matrix[_matrix.size()-1][i];
			if (current > sum) sum = current;
		}
		return sum;
	}

};

int main (int argc, char const* argv[])
{
	using namespace std;
	if (argc!=2) {
		cerr << "usage: " << argv[0] << " filename" << endl;
		return 1;
	}
	PathFinder test(argv[1]);
	return 0;
}

