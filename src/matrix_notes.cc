runtime errors

try { 
	insertPenis(): 
	if ( _penisGirth > _vag.getSize() ) 
		throw ( std::domain_error("exceeded vag bounds" ); 
} 
catch ( const std::exception & e ) { 
	std::cerr << e.what(); 
	exit(1); 
}

// arguments valid 
	// needs to check # of arguments
	// checks whether argv[2] is min or max
// file fails to open
vector fails to build (this seems resilient)
// vector is not a valid shape (currently fails invisibly)



if ( _matrix.size() == _matrix[_matrix.size()-1].size() ) {
	uint32_t squareCheck, triangleCheck;
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

} else return SHAPE_ERROR;


_matrix.size() = 5
first: 
_
_
_
_
_ _ _ _ _

next:      or
_          _
_          _
_          _
_ _ _ _    _ _ _ _ _
_ _ _ _ _  _ _ _ _ _

