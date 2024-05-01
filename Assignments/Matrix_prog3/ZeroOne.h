//---------------------------------------------------------
//
//		This header file shows the methods and variables 
//		used in the child class to perform variables
//		calculates to zero to one matrices
//
//---------------------------------------------------------

#ifndef ZEROONE_H
#define ZEROONE_H
#include "Matrix.h"

//ZeroOne is a child class to a private Matrix
 class ZeroOne : private Matrix
{
public:

	//Purpose:  Sets variables to default values     
	//Recieves: None
	//Returns:  None
	ZeroOne();

	//Purpose:  Sets variables to parameterized values    
	//Recieves: int r, c, and char type
	//Returns:  None
	ZeroOne(int r, int c, char type);

	//Purpose:  Sets variables to values in object
	//Recieves: object
	//Returns:  None
	ZeroOne(ZeroOne& object);

	//Purpose:  None  
	//Recieves: None 
	//Returns:  None
	~ZeroOne();

	//Purpose:	sets the number of rows
	//Recieves:	int r
	//Returns:	None
	void setrow(int r) { Matrix::setrow(r); };

	//Purpose:	sets the number of cols
	//Recieves:	int c
	//Returns:	None
	void setcol(int c) { Matrix::setcol(c); };

	//Purpose:	returns the number of rows
	//Receives:	None
	//Returns:	int
	int getrow() { return Matrix::getrow(); };

	//Purpose:	returns the number of cols
	//Receives:	None
	//Returns:	int
	int getcol() { return Matrix::getcol(); };

	//Purpose:	sets element
	//Receives:	row, col, value
	//Returns:	None
	void set_element(int r, int c, int i);

	//Purpose:	returns element
	//Receives:	row and col
	//Returns:	int
	int get_element(int i, int j) { return Matrix::get_element(i,j); };

	//Purpose:  Performs the join calculation of two 
	//			0 to 1 matrices
	//Recieves: object z1, and z2
	//Returns:  None
	void join(ZeroOne& z1, ZeroOne& z2);

	//Purpose:  Performs the meet calculation of two 
	//			0 to 1 matrices
	//Recieves: Object z1, and z2
	//Returns:  None
	void meet(ZeroOne& z1, ZeroOne& z2);

	//Purpose:  Transposes the matrices
	//Recieves: object z1
	//Returns:  None
	void transpose(ZeroOne& z1) { Matrix::transpose(z1); };

	//Purpose:  Checks if matrix is symmetric
	//Recieves: None
	//Returns:  None
	bool symmetry();

	//Purpose:  Transforms the matrices into strings
	//Recieves: None
	//Returns:  String
	string toString();

	//Purpose:  To overload the meet operator
	//Recieves: object of ZeroOne
	//Returns:  object of ZeroOne
	ZeroOne operator ^ (ZeroOne& z1);

	//Purpose:	Overloads the "=" operator
	//Recieves:	object of ZeroOne
	//Returns:	object of ZeroOne
	void operator = (const ZeroOne& z1) { Matrix::operator=(z1); };
	

private:
	//no private data
};

#endif