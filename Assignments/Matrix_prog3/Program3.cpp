//*************************************************************
//                                                            *
// Name: Cooper Wolf                                          *
//                                                            *
// Course: CS 2143, Fall 23, Stringfellow                     *
//                                                            *
// Purpose: This program reads in matrices and                *
//          performs operations with them. This program       *
//          uses overloaded operators for adding, multipling  *
//          and meeting. It then prints the results to the    *
//          given output file. The purpose of this program is *
//          to further my knowledge of matrices and to use    *
//          class inheritance, and overloaded operators       *
//                                                            *
//*************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Matrix.h"
#include "ZeroOne.h"

//including std's
using std::ifstream;
using std::ofstream;
using std::string;
using std::cout;
using std::cin;
using std::setw;
using std::endl;

//Purpose:  Prints heading  
//Recieves: outfile file
//Returns:  None
void heading(ofstream& outfile);

//Purpose:  Opens in and out files
//Receives: input file and output file
//Returns:  None
void openFiles(ifstream& infile, ofstream& outfile);

//Purpose:  Reads in the data from the input file
//Receives: Infile, r, r, a
//Returns:  None
void read_data(ifstream& infile, int& r, int& c, int a[][10]);

//Purpose:  inserts the elements from the array into the objects
//Receives: m, r, c, a 
//Returns:  None
void fill_matrix(Matrix& m, int r, int c, int a[][10]);

//Purpose:  inserts the elements from the array into the objects
//Receives: z, r, c, a
//Returns:  None
void fill_ZeroOne(ZeroOne& z, int r, int c,  int a[][10]);

//Purpose:  Prints the results
//Recieves: output file, matrix object and a bool
//Returns:  None
void symm_result(ofstream& outfile, Matrix& matrix, bool);

//Purpose:  Prints the results for transpose
//Recieves: output file, two objects of matrix
//Returns:  None
void T_result(ofstream& outfile, Matrix& m1, Matrix& m2);

//Purpose:  Prints the sum
//Receives: output file, three objects of matrix
//Returns:  None
void sum(ofstream& outfile, Matrix& m1, Matrix& m2, Matrix& m3);

//Purpose:  Prints the product
//Receives: output file, three objects of matrix
//Returns:  None
void product(ofstream& outfile, Matrix& m1, Matrix& m2, Matrix& m3);

//Purpose:  Adds matrices
//Receives: output file, three objects of matrix
//Returns:  None
void Adding(ofstream& outfile, Matrix& m1, Matrix& m2, Matrix& m3);

//Purpose:  Multiplies matrices
//Receives: output file, three objects of matrix
//Returns:  None
void Multiply(ofstream& outfile, Matrix& m1, Matrix& m2, Matrix& m3);

//Purpose:  Joins two zero to one matrices
//Receives: output file, three objects of ZeroOne
//Returns:  None
void join(ofstream& outfile, ZeroOne& z1, ZeroOne& z2, ZeroOne& z3);

//Purpose:  Meets two zero to one matrices
//Receives: output file, three objects of ZeroOne
//Returns:  None
void meet(ofstream& outfile, ZeroOne& z1, ZeroOne& z2, ZeroOne& z3);

//Purpose:  Prints the results of the meeting
//Receives: output file, three objects of ZeroOne
//Returns:  None
void m_results(ofstream& outfile, ZeroOne& z1, ZeroOne& z2,
               ZeroOne& z3);

//Purpose:  Prints the results to the joining
//Receives: output file, three objects of ZeroOne
//Returns:  None
void j_result(ofstream& outfile, ZeroOne& z1, ZeroOne& z2, ZeroOne& z3);

int main()
{
    //creating files
    ifstream infile;
    ofstream outfile;
 
    //opening files/printing heading
    openFiles(infile, outfile);
    heading(outfile);

    //creating variables
    int a[10][10];
    int amount = 0, r = 0, c = 0, r1 = 0, c2 = 0;
    char type = ' ';
    bool is_sym;

    //reading in the amount of couples of matrices in the input file
    infile >> amount;

    //looping to recieve all the data from input file
    for (int i = 0; i < amount; i++)
    {
        //reading in type
        infile >> type;

        //if type is 'R', then doing regular matrix
        if (type == 'R')
        {
            //reading and storing matrix 1
            read_data(infile, r, c, a);
            Matrix m1(r, c, type);
            fill_matrix(m1, r, c, a);

            //saving first row to mul
            r1 = r;

            //reading and storing matrix 2
            read_data(infile, r, c, a);
            Matrix m2(r, c, type);
            fill_matrix(m2, r, c, a);

            //saving second col mul
            c2 = c;

            //creating m3 and m4 object
            Matrix m3(r1, c2, type);
            Matrix m4(c, r, type);

            //add and mul
            Adding(outfile, m1, m2, m3);
            Multiply(outfile, m1, m2, m3);

            //transpose
            m4.transpose(m1);
            T_result(outfile, m1, m4);
            m4.transpose(m2);
            T_result(outfile, m2, m4);

            //checking symmetry
            is_sym = m1.symmetry();
            symm_result(outfile, m1, is_sym);
            is_sym = m2.symmetry();
            symm_result(outfile, m2, is_sym);
        }
        //else doing Zero to One operations
        else
        {
            //reading and storing z1
            read_data(infile, r, c, a);
            ZeroOne z1(r, c, type);
            fill_ZeroOne(z1, r, c, a);

            //reading and storing z2
            read_data(infile, r, c, a);
            ZeroOne z2(r, c, type);
            fill_ZeroOne(z2, r, c, a);

            //creating z3 object
            ZeroOne z3(r, c, type);

            //join and meeting matrices
            join(outfile, z1, z2, z3);
            meet(outfile, z1, z2, z3);
        }
        outfile << "\n\n---------------------------------------"
                <<"-------------\n\n";
    }
    //closing files
    infile.close();
    outfile.close();
    return 0;
}

//Purpose:  Prints heading    
void heading(ofstream& outfile)
{
    outfile << "*********************************************\n";
    outfile << "*       Cooper Wolf                         *\n";
    outfile << "*       CMPS 2433 - 101                     *\n";
    outfile << "*       Program 4: Overloading Operations   *\n";
    outfile << "*********************************************\n\n";
}

//Purpose:  Opens in and out files
void openFiles(ifstream& infile, ofstream& outfile)
{
    //characters to enter file names
    char inFileName[40];
    char outFileName[40];

    //opening user input file
    cout << "Enter the input file name: ";
    cin >> inFileName;
    infile.open(inFileName);

    //opening user output file
    cout << "Enter the output file name: ";
    cin >> outFileName;
    outfile.open(outFileName);
}

//Purpose:  Reads in the data from the input file
void read_data(ifstream& infile, int& r, int& c, int a[][10])
{
    //loop to read in file info
    infile >> r >> c;

    //nested loops to place values into first array
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            infile >> a[i][j];
        }
    }
}

//Purpose:  fills the matrix objects with values in the arrays
void fill_matrix(Matrix& m, int r, int c, int a[][10])
{
    int k;

    //loop to set matrix 1
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            k = a[i][j];
            m.set_element(i, j, k);
        }
    }
}

//Purpose:  fills the ZeroOne matrix with values in the arrays
void fill_ZeroOne(ZeroOne& z, int r, int c, int a[][10])
{
    int k;

    //loop to set ZeroOne 1
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            k = a[i][j];
            z.set_element(i, j, k);
        }
    }
}

//Purpose:  adds and prints matrix
void Adding(ofstream& outfile, Matrix& m1, Matrix& m2, Matrix& m3)
{
    //checking if addition can be performed
    if (m1.getrow() == m2.getrow() && m1.getcol() == m2.getcol())
    {
        m3 = m1 + m2;
        sum(outfile, m1, m2, m3);
        outfile << "\n\n";
    }
    //printing error message
    else
        cout << "\n\nCannot Perform Addition";
}

//Purpose:  Multiplies and prints matrix
void Multiply(ofstream& outfile, Matrix& m1, Matrix& m2, Matrix& m3)
{
    //checking if multiplication can be performed
    if (m1.getcol() == m2.getrow())
    {
        m3 = m1 * m2;
        product(outfile, m1, m2, m3);
        outfile << "\n\n";
    }
    //printing error message
    else
        cout << "\n\nCannot Perform Multiplication";
}

//Prupose:  joins the ZeroOne matrices
void join(ofstream& outfile, ZeroOne& z1, ZeroOne& z2, ZeroOne& z3)
{
    //checking if join operator can be performed
    if (z1.getrow() == z2.getrow() && z1.getcol() == z2.getcol())
    {
        z3.join(z1, z2);
        j_result(outfile, z1, z2, z3);
        outfile << "\n\n";
    }
    else
        cout << "\n\nCannot Perform Join";
}

//Purpose:  does meet operation
void meet(ofstream& outfile, ZeroOne& z1, ZeroOne& z2, ZeroOne& z3)
{
    //checking if meet operator can be performed
    if (z1.getrow() == z2.getrow() && z1.getcol() == z2.getcol())
    {
        z3 = z1 ^ z2;
        m_results(outfile, z1, z2, z3);
        outfile << "\n\n";
    }
    else
        cout << "\n\nCannot Perform Meet";
}

//Purpose:  Prints the sum
void sum(ofstream& outfile, Matrix& m1, Matrix& m2, Matrix& m3)
{
    outfile << endl << m1.toString();
    outfile << "\n+";
    outfile << endl << m2.toString();
    outfile << "\n=";
    outfile << endl << m3.toString();
}

//Purpose:  Prints the product
void product(ofstream& outfile, Matrix& m1, Matrix& m2, Matrix& m3)
{
    outfile << endl << m1.toString();
    outfile << "\n*";
    outfile << endl << m2.toString();
    outfile << "\n=";
    outfile << endl << m3.toString();
}

//Purpose:  prints results to join method
void j_result(ofstream& outfile, ZeroOne& z1, ZeroOne& z2, ZeroOne& z3)
{
    outfile << endl << z1.toString();
    outfile << "\n+";
    outfile << endl << z2.toString();
    outfile << "\n=";
    outfile << endl << z3.toString();
}

//Purpose:  Prints results of meet
void m_results(ofstream& outfile, ZeroOne& z1, ZeroOne& z2,
               ZeroOne& z3)
{
    outfile << endl << z1.toString();
    outfile << "\n^";
    outfile << endl << z2.toString();
    outfile << "\n=";
    outfile << endl << z3.toString();
}

//Purpose:  Prints the results
void symm_result(ofstream& outfile, Matrix& matrix, bool is_symm)
{
    //if statement to print whether symmetric or not
    if (is_symm)
        outfile << "\nMatrix is Symmetric\n";
    else
        outfile << "\nMatrix is not Symmetric\n";

    outfile << matrix.toString() << endl;
}

//Purpose:  Prints the results
void T_result(ofstream& outfile, Matrix& m1, Matrix& m2)
{
    outfile << endl << m1.toString();
    outfile << "\n T \n =";
    outfile << endl << m2.toString();
    outfile << endl;
}