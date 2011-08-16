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

#endif // _MATRIX_HPP