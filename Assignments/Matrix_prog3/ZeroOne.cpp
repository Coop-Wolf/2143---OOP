//---------------------------------------------------------
//
//		This ZeroMatrix.cpp file includes the definitions 
//		of all member functions. These functions all work
//		together to join, meet transpose, and check for 
//		symmetry.
//
//---------------------------------------------------------

#include "ZeroOne.h"
#include <iostream>
using std::cout;
using std::endl;

//Purpose:  Sets variables to default values
ZeroOne::ZeroOne() : Matrix()
{};

//Purpose:  Sets variables to parameterized values
ZeroOne::ZeroOne(int r, int c, char type) : Matrix(r, c, type)
{};

//Purpose:  Sets variables to values in object
ZeroOne::ZeroOne(ZeroOne& object) : Matrix(object)
{};

//Purpose: None
ZeroOne::~ZeroOne()
{};

//Purpose:  sets the element into the array
void ZeroOne::set_element(int r, int c, int i)
{
    Matrix::set_element(r, c, i);
}

//Purpose:  Performs the join operation
void ZeroOne::join(ZeroOne& z1, ZeroOne& z2) 
{
    //looping to join matrix
    for (int i = 0; i < z1.getrow(); i++)
     {
       for (int j = 0; j < z1.getcol(); j++)
         {
           a[i][j] = (z1.get_element(i, j) ||
                      z2.get_element(i, j));
         }
     }
}

//Purpose:  Performs the meet operation
void ZeroOne::meet(ZeroOne& z1, ZeroOne& z2)
{
    //looping to perform meet operation
   for (int i = 0; i < z1.getrow(); i++)
     {
       for (int j = 0; j < z1.getcol(); j++)
         {
           a[i][j] = (z1.get_element(i, j) &&
                      z2.get_element(i, j));
         }
     }
}

//Purpose:  Checks if matrices are symmetric
bool ZeroOne::symmetry()
{
    //calling matrix 
    bool sym;
    sym = Matrix::symmetry();
    return sym;
}

//Purpose:  Transforms the matrices into strings
string ZeroOne::toString()
{
    string s = "|------|\n|";

    //turning the array into a string
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            s += " " + std::to_string(a[i][j]) + " ";
        }
        s += "|\n|";
    }
    s += "------|";

    return s;
}

//Purpose:  Overloads '^' operator
ZeroOne ZeroOne::operator ^ ( ZeroOne& z1) 
{
    ZeroOne z2(z1.getrow(), z1.getrow(), z1.get_type());
    
    //looping to perform meet on zero one
	for (int i = 0; i < z1.getrow(); i++)
	{
		for (int j = 0; j < z1.getcol(); j++)
		{
			z2.a[i][j] = a[i][j] && z1.get_element(i, j);
		}
	}
	return z2;
}