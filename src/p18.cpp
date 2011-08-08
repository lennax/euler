#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <inttypes.h>
#include <vector>
#include <sstream>
#include <algorithm>

// prototype for int main {
// 	char * fileName = argv[1];
// 	char * compareType = argv[2];
// 	matrixReader matrixReaderInstance(fileName);
// 	if mR.isLoaded() // or try/catch (exceptions)
// 	switch(mR.getShape()) {
// 		case PF::SHAPE_SQUARE:
// 			pathFinder = new PathFinderSquare1(mR.getMatrix(), compareType);
// 		
// 	}
// }
	



class CostArray {
	private: 
		enum _shape_t {
			SHAPE_SQUARE, SHAPE_TRIANGLE, SHAPE_ERROR
		};
	public: 
		enum pathType_t {
			PATHTYPE_MIN, PATHTYPE_MAX
		};	
		
		CostArray (const char * fileName, pathType_t pathType) :
			_pathType(pathType) 
		{
			
		}
		
		virtual uint32_t getSum() = 0;

		uint32_t compare(uint32_t a, uint32_t b) {
			if (_pathType == PATHTYPE_MIN) {
				return std::min(a,b);
			}	
			else if (_pathType == PATHTYPE_MAX) {
				return std::max(a,b);
			}
		}
		
// read file and convert to vector of vectors (2D array)			
		_shape_t readFile(std::string fileName) {
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
	
		// determine whether matrix is triangle or square
	
			// std::cout << "height: " << _matrix.size() << std::endl;
			// std::cout << "0 width: " << _matrix[0].size() << std::endl;
			// std::cout << "n width: " << _matrix[_matrix.size()-1].size() << std::endl;
	
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

	// print the matrix
		void printMatrix() {
			using namespace std;
			for (int i=0;i<_matrix.size(); i++) {
				for (int j=0;j<_matrix[i].size();j++) 
					cout << _matrix[i][j] << "\t";
				cout << endl;
			}
		}
	private: 
		pathType_t _pathType;		
	protected:
		std::vector< std::vector<uint32_t> > _matrix;
		
		
};

class CostArraySquare1: public CostArray {
public:
	CostArraySquare1 (const char * fileName, pathType_t pathType) :
		CostArray(fileName, pathType)
	{
		
	}
	uint32_t getSum() {
		uint32_t sum = 0; 
			
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
				cur += compare(_matrix[y][x-1], _matrix[y-1][x]);
			}
		}
			
		sum = _matrix[_matrix.size()-1][_matrix.size()-1];
		return sum;
		
	}
	
};

class CostArrayTriangle1: public CostArray {
public:
	CostArrayTriangle1 (const char * fileName, pathType_t pathType) :
		CostArray(fileName, pathType)
	{
		
	}
	uint32_t getSum() {
		uint32_t sum = 0; 
		
		for (int y=1;y<_matrix.size(); y++) for (int x=0;x<y+1;x++) 
		{
			uint32_t & cur = _matrix[y][x];
			if (x==0) {
				cur += _matrix[y-1][x];
			} else if (x==y) {
				cur += _matrix[y-1][x-1];
			} else {
				cur += compare(_matrix[y-1][x], _matrix[y-1][x-1]);
			}
		}
		
		for (int i=0; i<_matrix.size(); i++) {
			uint32_t current = _matrix[_matrix.size()-1][i];
			if (i==0) sum = current;
			else sum = compare(sum,current);
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
	CostArray::pathType_t pathType;
	CostArray * costArray = NULL;
	if (strcmp(argv[2], "min") == 0)
			pathType = CostArray::PATHTYPE_MIN;
	else if (strcmp(argv[2], "max") == 0)
			pathType = CostArray::PATHTYPE_MAX;
	else {
			cerr << "usage: " << argv[0] << " filename (min|max)" << endl;
			cerr << "Second argument must be 'min' or 'max'." << endl;
			return 1;
	}
	
	costArray = new CostArrayTriangle1;
	costArray.getSum();

	// FIXME dont know it's a square
	CostArraySquare1 costArrayInstance(argv[1], pathType);
	return 0;
}

