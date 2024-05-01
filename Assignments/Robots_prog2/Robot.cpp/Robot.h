//**********************************************//
//	Header for the Robot class.                 //
// 	This class collects rocks and keeps         //
//  track of the distance it has travelled      //
//  as well as the amount of rocks collected    //
//**********************************************//

#ifndef ROBOT_H
#define ROBOT_H
#include "Rock_List.h"
#include <string>

class Robot
{
public:

//Purpose:  This default constructor sets
//			all variables to 0, false, and 
//			the empty string
//Receives: None
// 
//Returns:  None
Robot();

//Purpose:  This constructor sets
//			x and y to imputed values, 'on' to
//			false, and distance and rocks collected
//			to zero
//Receives: x, y coordinates
// 
//Returns:  None
Robot(int x, int y);

//Purpose:  This constructor sets the variables
//			to the values stored in the object
//			passed to it
//Receives: object of class Robot
// 
//Returns:  None
Robot(Robot& object);

//Purpose:  None
// 
//Receives: None
// 
//Returns:  None
~Robot() {};

//Purpose:  Sets x coordinate to value passed
//			to the function
//Receives: x coordinate
// 
//Returns:  None
void setx(int x);

//Purpose:  Sets y coordinate to value passed
//			to the function
//Receives: y coordinate
// 
//Returns:  None
void sety(int y);

//Purpose:  Returns the x coordinate
// 
//Receives: None
// 
//Returns:  x coordinate
int getx() const;

//Purpose:  Returns the y coordinate
// 
//Receives: None
// 
//Returns:  y coordinate
int gety() const;

//Purpose:  Sets the direction to the 
//			string passed to the function
//Receives: direction of the robot
// 
//Returns:  None
void setdirection(std::string direction);

//Purpose:  Returns the direction of the
//			robot
//Receives: None
// 
//Returns:  direction
std::string getdirection() const;

//Purpose:  Returns the traveled distance
//			of the robot
//Receives: None
// 
//Returns:  distance robot has traveled
double totaldistance() const;

//Purpose:  Determines the closest rock
// 
//Receives: Rock_List, Rock, position, and direction
// 
//Returns:  None
void findclosest_rock(Rock_List& list, Rock& rock, int& position,
	                  double& distance); 

//Purpose:  Picks up rocks, and updates list
// 
//Receives: List of rocks, rock, and position
// 
//Returns:  None
void collect(Rock_List& list, Rock& rock, int position);

//Purpose:	Gives the numbers of rocks collected
//
//Receives:	None
//
//Returns:	Number of rocks collected
int getrocks_collected() const;

//Purpose:  sets robot position to rock position
// 
//Receives: Rock list and position
// 
//Returns:  None
void move(Rock_List& list, int position);

//Purpose:  Increments total distance traveled by robot
// 
//Receives: double distance
// 
//Returns:  None
void distance(double distance);

//Purpose:  Turns the robot on to begin computing
// 
//Receives: None
// 
//Returns:  None
void power();

private:
	//member variables
	int x, y, collected;
	double traveled;
	bool on;
	std::string direction;
};

#endif