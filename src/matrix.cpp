#include "matrix.hpp"


// constructor
MatrixReader::MatrixReader (std::string fileName) :
	_fileName(fileName)
{			
	using namespace std;
	ifstream file;
	file.open(_fileName.c_str());

	if(!file.is_open()) {
		cout << "Could not open file: " << _fileName << endl;
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
	file.open(_fileName.c_str());
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

MatrixReader::matrix_t MatrixReader::getMatrix() {
	return _matrix;
}

// determine whether matrix is triangle or square
MatrixReader::shape_t MatrixReader::getShape() {
	// check height is equal to last row width
	if ( _matrix.size() == _matrix[_matrix.size()-1].size() ) {
		uint32_t triangleCheck = 0;
		uint32_t squareCheck = 0;
		
		for (uint32_t i=0; i<_matrix.size()-1; i++) {
			if ( _matrix[i].size() == i+1 ) 
				triangleCheck++;
			else if ( _matrix[i].size() == _matrix.size() ) 
				squareCheck++;
			else break;
		}
		if ( triangleCheck == _matrix.size()-1 ) 
			return SHAPE_TRIANGLE;
		else if ( squareCheck == _matrix.size()-1 )
			return SHAPE_SQUARE;
		else return SHAPE_ERROR;
	} 
	else return SHAPE_ERROR;	
}

void MatrixReader::printMatrix() {
	using namespace std;
	for (int i=0;i<_matrix.size(); i++) {
		for (int j=0;j<_matrix[i].size();j++) 
			cout << _matrix[i][j] << "\t";
		cout << endl;
	}
}


// constructor	
PathFinder::PathFinder (matrix_t matrix, pathType_t pathType) : 
	_matrix(matrix), _pathType(pathType)
{
}

uint32_t PathFinder::compare(uint32_t a, uint32_t b) {
	if (_pathType == PATHTYPE_MIN) {
		return std::min(a,b);
	}	
	else if (_pathType == PATHTYPE_MAX) {
		return std::max(a,b);
	}
}	



//constructor
PathFinderSquare1::PathFinderSquare1 (matrix_t matrix, pathType_t pathType) : 
	PathFinder(matrix, pathType) 
{
	//std::cout << "Sum: " << getSum() << std::endl;
}

uint32_t PathFinderSquare1::getSum() {
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



//constructor 
PathFinderTriangle1::PathFinderTriangle1 (matrix_t matrix, pathType_t pathType) :
	PathFinder(matrix, pathType)
{
	//std::cout << "Sum: " << getSum() << std::endl;
}

uint32_t PathFinderTriangle1::getSum() {
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


int main (int argc, char const* argv[])
{
	using namespace std;
	if (argc != 3) {
		cerr << "usage: " << argv[0] << " filename (min|max)" << endl;
		cerr << "Not enough arguments were supplied." << endl;
		exit(1);
	}
	MatrixReader mRInstance(argv[1]);
	
	// FIXME need MANY MANY error checkings
	// particularly # of argv
	// and is file open
	// and is the data perfectly formed
	// and blah 
	
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
	
	// initialize PathFinder abstract interface to NULL 
	PathFinder * p = NULL; 
	switch(mRInstance.getShape()) {
		case MatrixReader::SHAPE_SQUARE:
			p = new PathFinderSquare1(mRInstance.getMatrix(), pathType);
			std::cout << "Original Matrix: " << std::endl;
			mRInstance.printMatrix();
			break;
		case MatrixReader::SHAPE_TRIANGLE: 
			p = new PathFinderTriangle1(mRInstance.getMatrix(), pathType);
			break;
		default: 
			std::cerr << "Supplied data is not of a valid shape." << std::endl;
			exit(1);
	}

	std::cout << "Sum: " << p->getSum() << std::endl;
	
	// FIXME this still prints original matrix
	// presumably because PathFinder::getSum is editing PathFinder's _matrix
	// std::cout << "Computed Matrix: " << std::endl;
	// mRInstance.printMatrix();		

	// cleanup 
	delete p; 
	p = NULL;
}
