//******************************//
//	cpp file for Robot class    //
//******************************//

#include "Robot.h"

//Purpose:  This default constructor sets
//			all variables to 0, false, and 
//			the empty string
Robot::Robot()
{
	x = y = collected = 0;
    traveled = 0;
	direction = "";
	on = false;

}

//Purpose:  This constructor sets
//			x and y to imputed values, on to
//			false, and distance and rocks collected
//			to zero
Robot::Robot(int x, int y)
{
	this->x = x;
	this->y = y;
	on = false;
	collected = 0;
	traveled = 0;
}

//Purpose:  This constructor sets the variables
//			to the values stored in the object
//			passed to it
Robot::Robot(Robot& object)
{
	this->x = object.x;
	this->y = object.y;
	this->direction = object.direction;
	this->on = object.on;
	this->traveled = object.traveled;
	this->collected = object.collected;
}

//Purpose:  Sets x coordinate to value passed
//			to the function
void Robot::setx(int x)
{
	this->x = x;
}

//Purpose:  Sets y coordinate to value passed
//			to the function
void Robot::sety(int y)
{
	this->y = y;
}

//Purpose:  Returns the x coordinate
int Robot::getx() const
{
	return x;
}

//Purpose:  Returns the y coordinate
int Robot::gety() const
{
	return y;
}

//Purpose:  Sets the direction to the 
//			string passed to the function
void Robot::setdirection(std::string direction)
{
	this->direction = direction;
}

//Purpose:  Returns the direction of the
//			robot
std::string Robot::getdirection() const
{
	return direction;
}

//Purpose:  Returns the traveled distance
//			of the robot
double Robot::totaldistance() const
{
	return traveled;
}

//Purpose:  Determines the closest rock
void Robot::findclosest_rock(Rock_List& list, Rock& rock, 
							 int& position, double& distance)
{
	double d;
	
	//traversing the list of rocks
	for (int i = 0; i < list.getnumitems(); i++)
	{
		//only calculating distance of rocks not picked up yet
		//conditional not working, ispicked_up won't change to true.
		if (!list.getrock(i).ispicked_up())
		{
			//calculating distance between robot and rock
			d = sqrt(pow(list.getrock(i).getx() - x, 2) + 
				     pow(list.getrock(i).gety() - y, 2));

			//checking if rock is closer than other before
			if (d < distance)
			{
				//double to float, but won't change significant
				distance = d;

				//setting position to index of closest rock in the list
				position = i;
				
			}
		}	
	}
	//setting minimum distance rock to values
	rock = list.getrock(position);
}

//Purpose:	Picks up rocks, and updates list
void Robot::collect(Rock_List& list, Rock& rock, int position)
{
	//setting rock to picked up
	rock.setpicked_up();
	list.updatelist(rock, position);
	collected++;
}

//Purpose:	Gives the number of rocks collected
int Robot::getrocks_collected() const
{
	return collected;
}

//Purpose:	Sets robot position to rock position
void Robot::move(Rock_List& list, int position)
{
	x = list.getrock(position).getx();
	y = list.getrock(position).gety();
}

//Purpose:  Increments total distance traveled by robot
void Robot::distance(double distance)
{
	traveled += distance;
}

//Purpose:  Turns the robot on to begin computing
void Robot::power()
{
	on = true;
}