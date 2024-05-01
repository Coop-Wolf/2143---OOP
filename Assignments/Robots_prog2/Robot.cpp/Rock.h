//**********************************************//
//	Header for the rock class. This class		//
//	is used to give rocks coordinates and		//
//	determine if they are picked up by the      //
//	Robot.                                      //
//**********************************************//

#ifndef ROCK_H
#define ROCK_H

class Rock
{
public:
	
//Purpose:  This default constructor sets
//			the x, y, coodinates to 0, and
//			taken to false
//Receives: None
// 
//Returns:  None
Rock();

//Purpose:  This default constructor sets
//			the x, y, coordinates and taken
//			to values from paramemer 
//Receives: x and y coordinates, and taken(bool)
// 
//Returns:  None
Rock(int x, int y, bool taken);

//Purpose:  This default constructor sets
//			the x, y, coodinates and taken
//			to the values stored in object
//Receives: object of the same class
// 
//Returns:  None
Rock(Rock& object);

//Purpose:  None
// 
//Receives: None
// 
//Returns:  None
~Rock() {};

//Purpose:  Sets x coordinate to value
//			passed to the function
//Receives: x coordinate
// 
//Returns:  None
void setx(int x);

//Purpose:  To return the x coordinate
// 
//Receives: None
// 
//Returns:  x coordinate
int getx() const;

//Purpose:  Sets y coordinate to value
//			passed to the function
//Receives: y coordinate
// 
//Returns:  None
void sety(int y);

//Purpose:  To return the y coordinate
// 
//Receives: None
// 
//Returns:  y coordinate
int gety()const;

//Purpose:	Tells the rock if its been
//			picked up
//Receives:	None
//
//Returns:	None
void setpicked_up();

//Purpose:  Returns the status of whether
//			rock has been taken or not
// 
//Receives: None
// 
//Returns:  bool 
bool ispicked_up();

private:
	//member variables
	int x, y;
	bool taken;
};

#endif