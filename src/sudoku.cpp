#include "matrix.hpp"
#include <math.h> // for floor()

// Block 1: for (int y=0; y<3; y++) for (int x=0; x<3; x++)
// Block 2: for (int y=0; y<3; y++) for (int x=3; x<6; x++)
// Block 3: for (int y=0; y<3; y++) for (int x=6; x<9; x++)
// Block 4: for (int y=3; y<6; y++) for (int x=0; x<3; x++)
// Block 5: for (int y=3; y<6; y++) for (int x=3; x<6; x++)
// Block 6: for (int y=3; y<6; y++) for (int x=6; x<9; x++)
// Block 7: for (int y=6; y<9; y++) for (int x=0; x<3; x++)
// Block 8: for (int y=6; y<9; y++) for (int x=3; x<6; x++)
// Block 9: for (int y=6; y<9; y++) for (int x=6; x<9; x++)
//
// Row i: y=i; for (int x=0; x<9; x++)
//
// Col j: x=j; for (int y=0; y<9; y++)

class Sudoku {
	private:
		std::string _fileName; 
		uint8_t _sudoku[9][9]; 

	public: 
		Sudoku (std::string fileName) :
			_fileName(fileName)
		{
			using namespace std;

			ifstream fin(_fileName.c_str());
			uint8_t temp;

			for (uint16_t i = 0; i < 81; i++) {
				fin >> temp;
				uint16_t y = floor(i/9);
				uint16_t x = i%9;
				_sudoku[y][x] = temp;
				//cout << "(" << y << "," << x << ") ";
				//cout << temp << " ";
				//if ((i+1)%9 == 0) 
					//cout << endl;
			}
			fin.close();
			
		}

		uint8_t** getSudoku() {
			//return _sudoku;
		}

		void printSudoku() {
			for ( uint16_t i = 0; i < 9; i++ ) {	
				for ( uint16_t j = 0; j < 9; j++ ) {
					std::cout << _sudoku[i][j] << " ";
				}	
				std::cout << std::endl;
			}
		}

};


int main (int argc, char const* argv[]) {
	if (argc==1) {
		std::cerr << "Usage: " << argv[0] << " filename" << std::endl;
		exit(1);
	} 

	Sudoku sudokuInst(argv[1]);
	sudokuInst.printSudoku();
	//MatrixReader mRInstance(argv[1]);
	//mRInstance.printMatrix();
	return 0;
}
