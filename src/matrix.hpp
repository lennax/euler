#ifndef _MATRIX_HPP
#define _MATRIX_HPP

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <inttypes.h>
#include <string>
#include <vector>
#include <algorithm>

class MatrixReader {
	public: 
		typedef std::vector< std::vector<uint32_t> > matrix_t; 	
		enum shape_t {
			SHAPE_SQUARE, SHAPE_TRIANGLE, SHAPE_ERROR
		};		
	private:
		std::string _fileName; 
		matrix_t _matrix;
		
	public:
		// constructor
		MatrixReader (std::string fileName);

		matrix_t getMatrix();
		
		// determine whether matrix is triangle or square
		shape_t getShape();
		
		void printMatrix();
};

// abstract class
class PathFinder {
	public: 
		typedef std::vector< std::vector<uint32_t> > matrix_t; 
		
		enum pathType_t {
			PATHTYPE_MIN, PATHTYPE_MAX
		}; 
		
		virtual uint32_t getSum() = 0; 
		
		// constructor	
		PathFinder (matrix_t matrix, pathType_t pathType);

		uint32_t compare(uint32_t a, uint32_t b);
			
	private: pathType_t _pathType;
		
	protected: matrix_t _matrix; 		
};

class PathFinderSquare1: public PathFinder {
	public: 
		//constructor
		PathFinderSquare1 (matrix_t matrix, pathType_t pathType);
		uint32_t getSum();
};

class PathFinderTriangle1: public PathFinder {
	public: 
		//constructor 
		PathFinderTriangle1 (matrix_t matrix, pathType_t pathType);
		uint32_t getSum();	
}; 

#endif // _MATRIX_HPP