//---------------------------------------------------------
//
//		This Matrix.cpp file includes the definitions of
//		all member functions. These functions all work
//		together to add, multiply, transpose and check
//		if matrix is symmetric
//
//---------------------------------------------------------

#include "Matrix.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

//Purpose:  Sets variables to default values
Matrix::Matrix()
{
	r = 1;
	c = 1;
    type = 'R';
    a = nullptr;
}

//Purpose:  Sets variables to parameterized values
Matrix::Matrix(int r, int c, char type) 
{
	this->r = r;
    this->c = c;
    this->type = type;

    //Dynamically allocating 2-D array
    a = new int* [r];

    //loop to create each col
    for (int i = 0; i < r; i++) 
        a[i] = new int[c];
}

//Purpose:  Sets variables to values in object
Matrix::Matrix(Matrix& object)
{
	this->r = object.r;
	this->c = object.c;
    this->type = object.type;

    //Dynamically allocating 2-D array
    a = new int* [r];

    //loop to fill array with values in object
    for (int i = 0; i < r; i++)
    {
        a[i] = new int[c];
        for (int j = 0; j < c; j++)
        {
            a[i][j] = object.a[i][j];
        }
    }
}

//Purpose:  deletes the dynamic array
Matrix::~Matrix()
{
    //loop to delete each element
    for (int i = 0; i < r; i++)
         delete[] a[i];

    delete[] a;
}

//Purpose:  sets the number of rows
void Matrix::setrow(int r)
{
    this->r = r;
}

//Purpose:  sets the number of cols
void Matrix::setcol(int c)
{
    this->c = c;
}

//Purpose:  sets the element into the array
void Matrix::set_element(int r, int c, int i)
{
    a[r][c] = i;
}

//Purpose:  Adds the matrices together
void Matrix::add(Matrix& m1, Matrix& m2)
{
   //loop to add matrices
    for (int i = 0; i < m1.getrow(); i++)
     {
       for (int j = 0; j < m1.getcol(); j++)
        {
           a[i][j] = (m1.get_element(i, j) + m2.get_element(i, j));
        }
    }
}

//Purpose:  Performs matrix multiplication on the 
//			two matrices
void Matrix::mul(Matrix& m1, Matrix& m2)
{
     //looping to multiply matrices
     for (int i = 0; i < m1.getrow(); i++)
      {
        for (int j = 0; j < m2.getcol(); j++)
          {
            a[i][j] = 0;
            for (int k = 0; k < m1.getrow(); k++)
              {
                a[i][j] += m1.get_element(i, k) * m2.get_element(k, j);
              }
          }
      }
}

//Purpose:  Transposes the matrices
void Matrix::transpose(Matrix& m1)
{
    //loop to transpose the matrix
    for (int i = 0; i < m1.getrow(); ++i)
    {
        for (int j = 0; j < m1.getcol(); ++j)
        {
            a[j][i] = m1.get_element(i ,j);
        }
    }
}

//Purpose:  Checks if matrices are symmetric
bool Matrix::symmetry()
{
    //if rows and cols arent the same, its not symmetric
    if (r != c)
        return false;

    //looping to see if matrix is symmetric
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] != a[j][i])
                return false;
        }
    }
    return true;
}

//Purpose:  Transforms the matrices into strings
string Matrix::toString()
{
    string s = "|---------|\n|";

    //turning the array into a string
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            s +=  " " + std::to_string(a[i][j]) + " ";
        }
        s += "|\n|";
    }
    s += "---------|";

    return s; 
}

//Purpose:  Overloads the '+' operator
Matrix Matrix::operator + (const Matrix& m1)
{
    Matrix m2(r, c, type);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            m2.a[i][j] = a[i][j] + m1.a[i][j];
        }
    }
    return m2;
}

//Purpose:  Overloads the '*' operator
Matrix Matrix:: operator * (Matrix& m1)
{
    Matrix m2(r, c, type);

    for (int i = 0; i < m1.getrow(); i++)
    {
        for (int j = 0; j < m2.getcol(); j++)
        {
            m2.a[i][j] = 0;
            for (int k = 0; k < m1.getrow(); k++)
            {
                m2.a[i][j] += a[i][k] * m1.a[k][j];
            }
        }
    }
    return m2;
}

//Purpose:  Overloads the '=' operator
void Matrix::operator = (const Matrix& m1)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            a[i][j] = m1.a[i][j];
        }
    }
}