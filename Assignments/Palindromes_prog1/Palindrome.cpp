//---------------------------------------------------------
//
// Name: Cooper Wolf
//
// Course: CS 2143-101, Fall 23, Stringfellow
//
// Purpose:  This program will ask the user for
//           an outfile to send the results to.
//           It will asks the user to enter in
//           string. After they enter each string,
//           the program determines whether or not 
//           the string is a palindrome. 
//           
//---------------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>
#include "stk.h"

using namespace std;

//Purpose:  This function asks the user to enter
//          the name output file they wish to
//          store the results in. 
//Receives: The input parameters is an outfile
// 
//Returns:  It does not return anything, but prints out 
//          heading, and values to output file
void openfile(ofstream& outfile);

//Purpose:  This function prints out the heading
//          for my program
//Recieves: There is no input parameter
// 
//Returns:  This function is void, and does 
//          not return any value
void heading();

//Purpose:  This function prints out the heading
//          to the output file
//Recieves: The input parameter is an outfile
// 
//Returns:  This function is void, and does 
//          not return any value
void heading(ofstream& outfile);

//Purpose:  This function determines if the string
//          is a palindrome or not
//Recieves: The input parameter is the address of
//          a bool and the address of a string
//Returns:  This function does not return anything,
//          
void palindrome(bool& valid, string& word);

//Purpose:  This function prints the results to the
//          selected output file.
//Recieves: This function recieves the output file, 
//          the address of valid, and the address
//          of the original word
//Returns:  This function is void and does not return
//          anything.
void results(ofstream& outfile, bool valid, string& word);


int main()
{
    //creating outfile
    ofstream outfile;
    //creating variables
    char answer = 'y';
    string word;
    //calling functions to print heading
    //and open output file
    heading();
    openfile(outfile);

    cout << "\nWould you like to enter a string (y/n)? ";
    cin >> answer;

    //calls palindrome and prints results
    //until answer = n
    while (answer != 'n')
    {
        bool valid = false;
        palindrome(valid, word);
        results(outfile, valid, word);
        cout << "\nWould you like to enter another string (y/n)? ";
        cin >> answer;
    }
    //closing output file
    outfile.close();
    return 0;
}


//Purpose:  This function determines if a 
//          string is a palindrome or not
void palindrome(bool& valid, string& word)
{
    //creating onject
    CharStack stack(50);
    //creating variables
    char let;
    string rword = "";
    string word2 = "";

    cout << "\nEnter word/phrase: ";
    //clearing the white space with >> ws
    getline(cin >> ws, word);
    int length = word.length();

    //loop to get each character
    for (int i = 0; i < length; i++)
    {
        let = word.at(i);
        //blocking symbols from the string
        if (let >= 'A' && let <= 'Z' || let >= 'a' && let <= 'z')
        {
            //concatting characters
            word2 += toupper(let);
            //pushing each character onto the stack
            stack.push(toupper(let));
        }
    }
    //loop until the stop is empty
    while (!stack.isempty())
    {
        stack.pop(let);
        rword += let;
    }
    //determining if string is a 
    //palindrome
    if (rword == word2)
        valid = true; 
}

//Purpose:  This function creates an output 
//          file
void openfile(ofstream& outfile)
{
    char file[40];
    cout << "Enter output file you would like to send the results to: ";
    cin >> file;
    //opening output file
    outfile.open(file);
    heading(outfile);
}

//Purpose:  This function prints out the heading
//          for the program to the output file
void heading(ofstream& outfile)
{
    outfile << "***********************************\n";
    outfile << "*   Cooper Wolf                   *\n";
    outfile << "*   Program 1: Palindromes        *\n";
    outfile << "*   CMPS 2143 - 101               *\n";
    outfile << "***********************************\n\n";
}

//Purpose:  This funciton prins out the heading
//          for the program to the string
void heading()
{
    cout << "***********************************\n";
    cout << "*   Cooper Wolf                   *\n";
    cout << "*   Program 1: Palindromes        *\n";
    cout << "*   CMPS 2143 - 101               *\n";
    cout << "***********************************\n\n";
}

//Purpose:  This function prints the results to the
//          selected output file
void results(ofstream& outfile, bool valid, string& word)
{
    //printing strings to output file
    if (valid == true)
        outfile << word << " is a palindrome.\n";
    else
        outfile << word << " is not a palindrome.\n";
}