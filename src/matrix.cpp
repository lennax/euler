#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <inttypes.h>
#include <vector>
#include <sstream>
#include <algorithm>

class MatrixReader {
	public: 
		typedef std::vector< std::vector<uint32_t> > matrix_t; 	
		enum shape_t {
			SHAPE_SQUARE, SHAPE_TRIANGLE, SHAPE_ERROR
		};		
	private:
		const char * _fileName; 
		matrix_t _matrix;
		
	public:
		// constructor
		MatrixReader (const char * fileName) :
			_fileName(fileName)
		{			
		}

		matrix_t getMatrix() {
			// get the file blah blah 
		}
		
		shape_t getShape() {
			// get the shape
		}
};

// abstract class
class PathFinder {
	public: 
		typedef std::vector< std::vector<uint32_t> > matrix_t; 
		enum pathType_t {
			PATHTYPE_MIN, PATHTYPE_MAX
		};		
		// constructor	
		PathFinder (matrix_t matrix, pathType_t pathType) :
			_matrix(matrix), _pathType(pathType)
		{
		}
	private: 
		pathType_t _pathType;
		matrix_t _matrix; 		
};

class PathFinderSquare1: public PathFinder {
	public: 
		//constructor
		PathFinderSquare1 (matrix_t matrix, pathType_t pathType): 
			PathFinder(matrix, pathType) 
		{		
		}
};

class PathFinderTriangle1: public PathFinder {
	public: 
		//constructor 
		PathFinderTriangle1 (matrix_t matrix, pathType_t pathType) :
			PathFinder(matrix, pathType)
		{
		}	
}; 

int main (int argc, char const* argv[])
{
	using namespace std;
	const char * fileName = argv[1];
	// char * compareType = argv[2];
	MatrixReader mRInstance(fileName);
	
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
			break;
		case MatrixReader::SHAPE_TRIANGLE: 
			p = new PathFinderTriangle1(mRInstance.getMatrix(), pathType);
			break;
	}
}