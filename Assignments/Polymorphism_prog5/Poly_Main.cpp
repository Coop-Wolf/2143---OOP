//*************************************************************
//                                                            *
// Name: Cooper Wolf                                          *
//                                                            *
// Course: CS 2143, Fall 23, Stringfellow                     *
//                                                            *
// Purpose: This program reads in a data file of random       *
//			people. It uses polymorphism and creates an       *
//			array of pointers to "persons". It then prints    *
//			out all of the students from the input file       *
//			and changes the information of one student        *
//			The purpose of this program is to use polymorphic *
//          variables along with a static variable. This      *
//			This also reinforces the use of switch cases.     *
//                                                            *
//*************************************************************

//include libraries
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Person.h"
#include "Student.h"
#include "NonDegreeStudent.h"
#include "GraduateStudent.h"

//including standard
using namespace std;

//Purpose: open input and output streams
//Requires: ifstream, ofstream
//Returns: opened streams
void openFiles(ifstream& infile, ofstream& outfile);

//Prupose:  Prints heading
//Requires: ofstream
//Returns:  None
void heading(ofstream& outfile);

//Purpose:  reads data
//Receives: ifstream, int
//Returns:  None
void read_data(ifstream& infile, Person* people[], int amount);

//Purpose:  creats rows for output
//Receives: ofstream
//Returns:  None
void format(ofstream& outfile);

//Purpose:  Prints number of students
//Recieves: ofstream, array of pointers, int
//Returns:  None
void numstudents(ofstream& outfile, Person* people[], int amount);

//Purpose:  Prints Carol's new info
//Recieves: ofstream, array of pointers, int
//Returns:  None
void new_Carl(ofstream& outfile, Person* people[], int amount);

//Purpose:  prints results
//Recieves: ofstream, array of pointers, int
//Returns:  None
void results(ofstream& outfile, Person* people[], int amount);

//Purpose:  graduates student
//Recieves: ofstream, array of pointers
//Returns:  None
void student_grad(ofstream& outfile, Person* people[]);

int main()
{
    //opening streams
    ifstream infile;
    ofstream outfile;

    //creating files and printing heading
    openFiles(infile, outfile);
    heading(outfile);

    //creating variables
    Person* people[50];
    int amount;

    //reading in amount of people
    infile >> amount;

    //reading data
    read_data(infile, people, amount);

    //printing number of students
    numstudents(outfile, people, amount);

    //printing results
    format(outfile);
    results(outfile, people, amount);
    format(outfile);

    //printing Carl's new info
    new_Carl(outfile, people, amount);

    //deleting array and closing files
    delete[] * people;
    infile.close();
    outfile.close();
	return 0;
}

//Purpose:  Prints heading    
void heading(ofstream& outfile)
{
    outfile << "*********************************************\n";
    outfile << "*       Cooper Wolf                         *\n";
    outfile << "*       CMPS 2143 - 101                     *\n";
    outfile << "*       Program 5: Polymorphism             *\n";
    outfile << "*********************************************\n\n";
}

//Purpose:  Opens in and out streams
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

//Purpose:  Prints number of students
void numstudents(ofstream& outfile, Person* people[], int amount)
{
    //downcasting
    Student* stu = dynamic_cast<Student*>(people[amount]);
    outfile << "There are " << stu->getNumStudents() << " students";
    outfile << " attending MSU\n";
}

//Purpose:  reads data
void read_data(ifstream& infile, Person* people[], int amount)
{
    //creating variables
    char type, mi;
    string fn, ln, title, major, topic, advisor;
    float gpa;

    //for loop to read all data
    for (int i = 0; i <= amount; i++)
    {
        //reading in basic info
        infile >> type >> fn >> mi >> ln >> title;

        //switch case to store info of different people
        switch (type)
        {
            case 'S':
            {
                //reading in all student info
                infile >> gpa >> major;
                people[i] = new Student(fn, ln, mi, title, gpa, major);
            }break;

            case 'N':
            {
                //reading in all nondegree info
                infile >> gpa;
                people[i] = new NonDegreeStudent(fn, ln, mi, title, gpa,
                                                 "NonDegree");
            }break;

            case 'G':
            {
                //reading in all graduate info
                infile >> gpa >> major >> advisor;

                //reads in whole line and gets rid of junk
                getline(infile >> ws, topic);
                people[i] = new GraduateStudent(fn, ln, mi, title, gpa,
                                                major, topic, advisor);
            }break;

            case 'P':
            {
                //assigning person
                people[i] = new Person(fn, ln, mi, title);
            }break;
        }
    }
}

//Purpose:  Prints Carol's new info
void new_Carl(ofstream& outfile, Person* people[], int amount)
{
    outfile << "\nCarl's new information\n";
    outfile << "--------------------------------------------------\n";

    //loop to find carl in list
    for (int i = 0; i <= amount; i++)
    {
        if (people[i]->getFirstName() == "Carl")
        {
            //downcasting and granting carl his PhD
            GraduateStudent* stu = dynamic_cast<GraduateStudent*>
                                                     (people[i]);
            stu->EarnPhD();
            outfile << people[i]->toString();
        }
    }
    outfile << "\n--------------------------------------------------\n";
}

//Purpose:  prints results
void results(ofstream& outfile, Person* people[], int amount)
{
    string is_student = " ";

    //loop to traverse array
    for (int i = 0; i <= amount; i++)
    {
        //setting variable to student or person
        is_student = people[i]->isA();

        //printing only if people is a student
        if (is_student != "Person")
        {
            outfile << people[i]->toString() << endl;
        }
    }
}

//Purpose:  creats rows for output
void format(ofstream& outfile)
{
    outfile << "--------------------------------------------------\n";
}