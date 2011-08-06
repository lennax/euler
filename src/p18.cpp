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
	enum pathType_t {
		PATHTYPE_MIN, PATHTYPE_MAX
	};	
	PathFinder (const char * fileName, pathType_t pathType) {
	// PathFinder (const char * fileName) {
		using namespace std;
		//cout << "filename: " << endl;
		//std::string fileName;
		//cin >> fileName;
		readFile(string(fileName));
		
		cout << "Original matrix:" << endl;
		printMatrix();	

		uint32_t sum = getSum(pathType);

		cout << "Computed matrix:" << endl;
		printMatrix();
		cout << "sum: " << sum << endl;

	}
private:
	std::vector< std::vector<uint32_t> > _matrix;
	enum _shape_t {
		SHAPE_SQUARE, SHAPE_TRIANGLE, SHAPE_ERROR
	};
	
// read file and convert to vector of vectors (2D array)
	void readFile(std::string fileName) {
		using namespace std;
		ifstream file;
		file.open(fileName.c_str());

		if(!file.is_open()) {
			cout << "could not open file: " << fileName << endl;
			exit(1);
		}

		// Read a line and look for comma, else assume space
		string delimTest;
		char delimiter;
		getline(file,delimTest,'\n'); 
		if (delimTest.find(",") != string::npos) {
			delimiter = ',';
		} else { 
			delimiter = ' '; 
		}
		// Close and reopen file
		file.close();
		file.open(fileName.c_str());
		// Read lines into vector vector
		string line;
		while (!getline(file,line,'\n').eof()) {
			istringstream reader(line);
			vector<uint32_t> lineData;
			uint32_t number;
			string number_str;
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
	_shape_t getShape()
   	{
		std::cout << "height: " << _matrix.size() << std::endl;
		std::cout << "0 width: " << _matrix[0].size() << std::endl;
		std::cout << "n width: " << _matrix[_matrix.size()-1].size() << std::endl;
		// check height is equal to last row width
		if ( _matrix.size() == _matrix[_matrix.size()-1].size() ) {
			// square first row width is equal to last row width
			if ( _matrix[_matrix.size()-1].size() == _matrix[0].size() ) {
				return SHAPE_SQUARE;
			// triangle first row width is 1
			} else if ( _matrix[0].size() == 1 ) {
				return SHAPE_TRIANGLE;
			}
		} else return SHAPE_ERROR; 
	}

	void printMatrix() {
		using namespace std;
		for (int i=0;i<_matrix.size(); i++) {
			for (int j=0;j<_matrix[i].size();j++) 
				cout << _matrix[i][j] << "\t";
			cout << endl;
		}
	}

// triangle addition logic
	uint32_t getSum(pathType_t pathType) {
		_shape_t shape = getShape();
		switch (shape) {
			case SHAPE_TRIANGLE: 
				for (int y=1;y<_matrix.size(); y++) for (int x=0;x<y+1;x++) 
				{
					uint32_t & cur = _matrix[y][x];
					if (x==0) {
						cur += _matrix[y-1][x];
					} else if (x==y) {
						cur += _matrix[y-1][x-1];
					} else {
						switch(pathType) {
							case PATHTYPE_MIN:
								cur += std::min(_matrix[y-1][x], _matrix[y-1][x-1]);
								break;
							case PATHTYPE_MAX:
								cur += std::max(_matrix[y-1][x], _matrix[y-1][x-1]);
								break;
						};
					}
				}
				break;
			case SHAPE_SQUARE:
				for (int y=0; y<_matrix.size(); y++) for (int x=0; x<_matrix.size(); x++)
				{
					uint32_t & cur = _matrix[y][x];
					if (y == 0 && x == 0) {
						continue;
					}
					else if (y == 0) {
						cur += _matrix[y][x-1];
					} else if (x == 0) {
						cur += _matrix[y-1][x];
					} else {
						switch(pathType) {
							case PATHTYPE_MIN: 
								cur += std::min(_matrix[y][x-1], _matrix[y-1][x]);
								break;
							case PATHTYPE_MAX: 
								cur += std::max(_matrix[y][x-1], _matrix[y-1][x]);
								break;
						}	
					}
				}
				break;
			default:
				std::cerr << "The supplied matrix is not a recognized shape." 
					<< std::endl;
				exit(1); 
		}

		uint32_t sum;
		if (shape == SHAPE_TRIANGLE) {
			for (int i = 0; i < _matrix.size(); i++) {
				uint32_t current = _matrix[_matrix.size()-1][i];
				if (i == 0) sum = current;
				switch(pathType) { 
					case PATHTYPE_MIN: 
						if (current < sum) sum = current;
						break;
					case PATHTYPE_MAX:
						if (current > sum) sum = current;
						break;
				}
			}
		} else if (shape == SHAPE_SQUARE) {
			sum = _matrix[_matrix.size()-1][_matrix.size()-1];
		}
		return sum;
	}

};

int main (int argc, char const* argv[])
{
	using namespace std;
	if (argc!=3) {
		cerr << "usage: " << argv[0] << " filename (min|max)" << endl;
		return 1;
	}
	PathFinder::pathType_t pathType;
	if (strcmp(argv[2], "min") == 0)
			pathType = PathFinder::PATHTYPE_MIN;
	else if (strcmp(argv[2], "max") == 0)
			pathType = PathFinder::PATHTYPE_MAX;
	else {
			cerr << "usage: " << argv[0] << " filename (min|max)" << endl;
			cerr << "Second argument must be 'min' or 'max'." << endl;
			return 1;
	}

	PathFinder test(argv[1], pathType);
	// PathFinder test(argv[1]);
	return 0;
}

