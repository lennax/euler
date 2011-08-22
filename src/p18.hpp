#ifndef _P18_HPP
#define _P18_HPP

#include "matrix.hpp"
#include <string.h> // for strcmp() maybe

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

#endif // _P18_HPP
