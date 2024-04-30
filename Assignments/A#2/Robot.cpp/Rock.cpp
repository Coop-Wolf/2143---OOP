//******************************//
//	cpp file for Rock class		//
//******************************//

#include "Rock.h"

//Purpose:  This default constructor sets
//			the x, y, coodinates to 0, and
//			taken to false
Rock::Rock()
{
	x = 0;
	y = 0;
	taken = false;
}

//Purpose:  This default constructor sets
//			the x, y, coordinates and taken
//			to values from paramemer 
Rock::Rock(int x, int y, bool taken)
{
	this->x = x;
	this->y = y;
	this->taken = taken;

}

//Purpose:  This default constructor sets
//			the x, y, coodinates and taken
//			to the values stored in object
Rock::Rock(Rock& object)
{
	this->x = object.x;
	this->y = object.y;
	this->taken = object.taken;
}

//Purpose:  Sets x coordinate to value
//			passed to the function
void Rock::setx(int x)
{
	this->x = x;
}

//Purpose:  To return the x coordinate

int Rock::getx() const
{
	return x;
}

//Purpose:  Sets y coordinate to value
//			passed to the function
void Rock::sety(int y)
{
	this->y = y;
}

//Purpose:  To return the y coordinate

int Rock::gety() const
{
	return y;
}

//Prupose:	Tells the rock if its been
//			picked up
void Rock::setpicked_up()
{
	taken = true;
}

//Purpose:  Determines if rock is picked
//			up or not
bool Rock::ispicked_up()
{
	return taken;
}