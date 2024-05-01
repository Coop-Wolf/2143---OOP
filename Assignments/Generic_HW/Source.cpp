// Name:	 Cooper Wolf
// Course:	 CS 2143-101, Fall 23, Stringfellow
// Purpose:  This program uses a templated function to 
//			 swap various variables.

#include <fstream>
using std::ofstream;
using std::endl;

//Purpose:	Swaps two variables
//Recieves:	variables
//Returns:	None
template <typename Var>
void swap(Var& x, Var& y);

int main()
{
	//creating stream
	ofstream outfile;
	outfile.open("result.txt");

	//creating varibles
	int x = 1, y = 10;
	double c = 3.98, d = 8.34;
	char let1 = 'a', let2 = 'b';

	outfile << "x = " << x << ", y = " << y << endl;
	swap<int>(x, y);
	outfile << "x = " << x << ", y = " << y << endl << endl;

	outfile << "x = " << c << ", y = " << d << endl;
	swap<double>(c, d);
	outfile << "x = " << c << ", y = " << d << endl << endl;

	outfile << "let1 = " << let1 << ", let2 = " << let2 << endl;
	swap<char>(let1, let2);
	outfile << "let1 = " << let1 << ", let2 = " << let2;
}

//Purpose:	Swaps two variables
template <typename Var>
void swap(Var& x, Var& y)
{
	Var tmp = x;
	x = y;
	y = tmp;
}