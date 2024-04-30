//-------------------------------------------------------//
//                                                       //
// Name: Cooper Wolf                                     //
//                                                       //
// Course: CS 2143-101, Fall 23, Stringfellow            //
//                                                       //
// Purpose:  This program shows the process of a         //
//           robot on mars collecting rocks. The         //
//           program reads in rock coordinates from      //
//           an input file and and asks the uses for     //
//           the coordinates of the robot anlong with    //
//           the number of rocks they would like to      // 
//           collect calculates the closest rock to      //
//           the robot. The robot "collects" a number    //
//           of rocks determined by the user. when all   //
//           collection is over. The program outputs     //
//           all of the data to the output file          //
//                                                       //
//-------------------------------------------------------//

#include <iostream>
#include<fstream>
#include "iomanip"

//class headers
#include "Rock.h"
#include "Rock_List.h"
#include "Robot.h"

//including std
using std::cout;
using std::cin;
using std::ofstream;
using std::ifstream;
using std::fixed;
using std::setprecision;
using std::right;
using std::setw;
using std::endl;

//Purpose:  This function prints out the heading
//      
//Recieves: The input parameter is an outfile
// 
//Returns:  None
void heading(ofstream& outfile, int amount);

//Purpose:  This function opens in/out files
// 
//Receives: infile and outfile
// 
//Returns:  None
void openFiles(ifstream& infile, ofstream& outfile);

//Purpose:  This function asks to user how
//          many rocks to collect and the 
//          robot position.
//Receives: Robot x and y cooridinate, and
//          the amount of rocks to be collected
//Returns:  None
void input(int& rx, int& ry, int& amount);

//Purpose:  Stores rocks into the rock list
//
//Receives: input file, rock list, object rock, int i
//
//Returns:  None
void storing_rocks(ifstream& infile, Rock_List& rlist, Rock& rock,
                   int& i);

//Purpose:  Print out robot final distance traveled
// 
//Receives: output file and object of Robot
//
//Returns:  None
void finaldistance(ofstream& outfile, Robot& robot);

//Purpose:  Prints the results to the output file
//
//Recieves: output file, rock, position and distance
//
//Returns:  None
void results(ofstream& outfile, Rock rock,
             int position, double distance);

//Purpose:  Prints beginning info of robot
//
//Recieves: output file and object of Robot
//
//Returns:  None
void beginning_data(ofstream& outfile, Robot robot);

//Purpose:  Getting the closest rock in the list
//
//Recieves: output file, rock list, rock, robot, amount,
//          position, and distance
//Returns:  None
void closest_rock(ofstream& outfile, Rock_List& rlist, Rock rock,
                  Robot& robot, int amount, int& position,
                  double& distance);

//Purpose:  Make sure user entered valid input
//
//Recieves: amount of rocks user wants, robot x/y coordinates
//          and int i
//Returns:  None
void input_validation(int& amount, int& rx, int& ry, int i);


int main()
{
    //creating files
    ifstream infile;
    ofstream outfile;

    // number of rocks to collect, and
    // rock x and y coordinates
    int amount;
    int rx, ry;

    //variables for finding closest rock
    int position;
    double distance;

    //to check valid user input
    int i = 0;

    //opening files
    openFiles(infile, outfile);

    //getting user input
    input(rx, ry, amount);

    //creating objects
    Rock_List rlist;
    Rock rock;
    
    //storing rocks into rock list
    storing_rocks(infile, rlist, rock, i);

    //checking user input
    input_validation(amount, rx, ry, i);

    //creating robot object and turning it on
    Robot robot (rx, ry);

    //calling heading function
    heading(outfile, amount);

    //turning on robot
    robot.power();

    //printing beginning info of robot
    beginning_data(outfile, robot);

    //calling function to get closest rock
    closest_rock(outfile, rlist, rock, robot, amount, position,
                 distance);

    //printing total distance of robot
    finaldistance(outfile, robot);

    //closing files
    infile.close();
    outfile.close();

    return 0;
    //End of Main
}

//Function definitions

//Purpose:  This function prints out the heading
//          
void heading(ofstream& outfile, int amount)
{
    outfile << "*******************************************\n";
    outfile << "*         Cooper Wolf                     *\n";
    outfile << "*         CMPS 2143 - 101                 *\n";
    outfile << "*         Program 2: Robots on Mars       *\n";
    outfile << "*******************************************\n\n";
    outfile << "-------------------------------------------\n";
    outfile << "The robot collected " << amount << " rocks\n";
    outfile << "-------------------------------------------\n";
    outfile << "Rock collected\t Position\t Distance (mi)\n";
}

//Purpose:  This function opens an infile 
//          and outfile
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

//Purpose:  This function asks the user
//          for the number of rocks collected
//          and the robots location
void input(int& rx, int& ry, int& amount)
{
    //getting user input
    cout << "\nHow many rocks would you like collected? ";
    cin >> amount;
    cout << "\nPlease enter the robot's position";
    cout << "\nx: ";
    cin >> rx;
    cout << "y: ";
    cin >> ry;
}

//Purpose:  Stores rocks into the rock list
void storing_rocks(ifstream& infile, Rock_List& rlist, Rock& rock,
                   int& i)
{    
    //variables to store input
    int x;
    int y;

    //storing rocks into list
    while (infile >> x >> y)
    {
        rock.setx(x);
        rock.sety(y);
        rlist.addrock(rock);
        i++;
    }
}

//Purpose:  Prints results to output file
void results(ofstream& outfile, Rock rock, int position,
             double distance)
{
    outfile << setw(4) << position+1 << setw(15) << "(" 
            << rock.getx() << ", " << rock.gety() << ")" 
            << setw(11) << fixed << setprecision(2) << right 
            << distance << endl;
}

//Purpose:  Print out the final distance traveled
//          by the robot
void finaldistance(ofstream& outfile, Robot& robot)
{
    outfile << "-------------------------------------------";
    outfile << "\nThe robot traveled " << robot.totaldistance() 
            << " miles\n";
    outfile << "-------------------------------------------";
}

//Purpose:  Prints beginning info of robot
void beginning_data(ofstream& outfile, Robot robot)
{
    outfile << setw(4) << "-" << setw(15) << "(" 
            << robot.getx() << ", " << robot.gety()
            << ")" << setw(11) << fixed << setprecision(2) 
            << right << robot.totaldistance() << endl;
}

//Purpose:  Getting the closest rock in the list
void closest_rock(ofstream& outfile, Rock_List& rlist, Rock rock,
                  Robot& robot, int amount, int& position,
                  double& distance)
{
    //for loop to get closest rocks and print all data to screen
    for (int j = 0; j < amount; j++)
    {
        double distance = 100;

        //finding closest rock
        robot.findclosest_rock(rlist, rock, position, distance);

        //print results
        results(outfile, rock, position, distance);

        //moving rock to position of closest rock
        robot.move(rlist, position);

        //incrementing rocks picked up
        robot.collect(rlist, rock, position);

        //adding distance to total distance traveled
        robot.distance(distance);
    }
}

//Purpose:  Checks for valid input
void input_validation(int& amount, int& rx, int& ry, int i)
{
    //making sure user entered valid input
    while (amount > i || 0 > rx || rx > 100 || 0 > ry || ry > 100)
    {
        cout << "\nError! Please redo with correct values.\n";
        input(rx, ry, amount);
    }
}