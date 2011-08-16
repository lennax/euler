#include "p18.hpp"

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


void printUsage(char const* argv_0) {
	std::cerr << "Usage: " << argv_0 << " filename (min|max)" << std::endl; 
}



int main (int argc, char const* argv[])
{
	using namespace std;
	// will not run without additional argument
	if (argc == 1) {
		printUsage(argv[0]);
		cerr << "Not enough arguments were supplied." << endl;
		exit(1);
	}
	// single argument must be either help or a problem
	else if (argc == 2 ) {
		if ( strcmp(argv[1], "help") == 0 ) {
			printUsage(argv[0]);
			cerr << "Help stuff" << endl;
			exit(0); // not exactly an error
		}
		else if ( strcmp(argv[1], "p18") == 0 ) {
			argv[1] = "data/triangle4.txt";
			argv[2] = "max";
		}	
		else if ( strcmp(argv[1], "p67") == 0 ) {
			argv[1] = "data/triangle100.txt";
			argv[2] = "max";
		}	
		else if ( strcmp(argv[1], "p81") == 0 ) {
			argv[1] = "data/matrix.txt";
			argv[2] = "min";
		}	
		else {
			printUsage(argv[0]);
			cerr << "Not enough arguments were supplied." << endl;
			exit(1);
		}
	}

	// run with either problem file or argument file
	MatrixReader mRInstance(argv[1]);

	// match second argument to pathType enum
	PathFinder::pathType_t pathType; 
	if (strcmp(argv[2], "min") == 0)
		pathType = PathFinder::PATHTYPE_MIN;
	else if (strcmp(argv[2], "max") == 0)
		pathType = PathFinder::PATHTYPE_MAX;
	else {
		printUsage(argv[0]);
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
