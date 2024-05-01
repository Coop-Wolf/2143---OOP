//---------------------------------------------------------
//
//		This header file shows the methods and variables 
//		used in the parent class to perform variables
//		calculates to matrices
//
//---------------------------------------------------------

#ifndef MATRIX_H
#define MATRIX_H
#include <string>
using std::string;

class Matrix
{

public:

	//to access private variables
	friend class ZeroOne;

	//Purpose:  Sets variables to default values
	//Recieves: None
	//Returns:  None
	Matrix();

	//Purpose:  Sets variables to parameterized values
	//Recieves: rows, cols, type
	//Returns:  None
	Matrix(int r, int c, char type);

	//Purpose:  Sets variables to values in object
	//Recieves: object
	//Returns:  None
	Matrix(Matrix& object);

	//Purpose:  deletes the dynamic array
	//Recieves: None
	//Returns:  None
	 ~Matrix();

	//Purpose:	sets the number of rows
	//Recieves:	int r
	//Returns:	None
	void virtual setrow(int r);

	//Purpose:	sets the number of cols
	//Recieves:	int c
	//Returns:	None
	void virtual setcol(int c);

	//Purpose:	returns number of rows
	//Recieves:	None
	//Returns:	int
	int virtual getrow() { return r; };

	//Purpose:	returns number of cols
	//Receives:	None
	//Returns:	int
	int virtual getcol() { return c; };

	//Purpose:	sets element
	//Receives:	row, col, value
	//Returns:	None
	void virtual set_element(int r, int c, int i);

	//Purpose:	returns element
	//Receives:	row and col
	//Returns:	int
	int virtual get_element(int i, int j) { return a[i][j]; };

	//Purpose:	returns the type of matrix
	//Receives:	None
	//Returns:	type of matrix
	char virtual get_type() { return type; }

	//Purpose:  Adds the matrices together
	//Recieves: Matrix objects, m1 and m2
	//Returns:  None
	void virtual add(Matrix& m1, Matrix& m2);

	//Purpose:  Performs matrix multiplication on the 
	//			two matrices
	//Recieves: Matrix objects m1, m2
	//Returns:  None
	void virtual mul(Matrix& m1, Matrix& m2);

	//Purpose:  Transposes the matrix
	//Recieves: Matrix object
	//Returns:  None
	void virtual transpose(Matrix& m1);

	//Purpose:  Checks if matrices are symmetric
	//Recieves: None
	//Returns:  bool
	bool virtual symmetry();

	//Purpose:  Transforms the matrices into strings
	//Recieves: None
	//Returns:  string
	string virtual toString();

	//Purpose:	Overloads the '+' operator
	//Recieves:	m1 object
	//Returns:	Matrix type
	Matrix operator + (const Matrix& m1);

	//Purpose:	Overloads the '*' operator
	//Recieves:	m1 object
	//Returns:	Matrix type
	Matrix operator * (Matrix& m1);

	//Purpose:	Overloads the '=' operator
	//Recieves:	m1 object
	//Returns:	None
	void operator = (const Matrix& m1);
	
private:

	//2-D array
	int** a;
	int r;
	int c;
	char type;
};

#endif