#include "matrix.hpp"

// constructor
MatrixReader::MatrixReader (std::string fileName) :
	_fileName(fileName)
{			
	using namespace std;
	ifstream file;
	file.open(_fileName.c_str());

	if(!file.is_open()) {
		cerr << "Could not open file: " << _fileName << endl;
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
		// count valid rows
		uint32_t triangleCheck = 0;
		uint32_t squareCheck = 0;
		for (uint32_t i=0; i<_matrix.size()-1; i++) {
			// square is constant width
			if ( _matrix[i].size() == _matrix.size() ) 
				squareCheck++;
			// triangle increases stepwise
			else if ( _matrix[i].size() == i+1 ) 
				triangleCheck++;
			else break;
		}
		// number of valid rows should match height
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


