//*******************************//
//	cpp file for Rock_List class //
//*******************************//


#include "Rock_List.h"
#include <iostream>

//Purpose:  This default constructor sets
//			the capacity to 100, creates
//			an array of 100 rocks and sets
//			nunitems to 0
Rock_List::Rock_List()
{
	capacity = 100;
	rocks = new Rock[capacity];
	numitems = 0;
}

//Purpose:	This constructor sets the capacity
//			to value in the parameter
Rock_List::Rock_List(int capacity)
{
	this->capacity = capacity;
	rocks = new Rock[capacity];
	numitems = 0;
}

//Purpose:  This constructor sets variables
//			to values stored in object
Rock_List::Rock_List(Rock_List& object)
{
	this->capacity = object.capacity;
	this->numitems = object.numitems;
	rocks = new Rock[object.capacity];
}

//Pupose:	Puts a rock into the array
void Rock_List::addrock(Rock& item)
{
	//checking if stack is full
	if(numitems >= capacity - 1)
		std::cout << "Stack is full";
	//if not full, adding new rock to array
	else
	{
		rocks[numitems] = item;
		numitems++;
	}
}

//Purpose:	Returns the number of rocks in list
int Rock_List::getnumitems() const
{
	return numitems;
}

//Purpose:	Returns a rock at the given index
Rock Rock_List::getrock(const int i)
{
	return rocks[i];
}

//Purpose:	to update the rocklist
void Rock_List::updatelist(Rock& rock, int i)
{
	rocks[i] = rock;
}

//Purpose:	Remove rock from array
void Rock_List::remove_rock(Rock& item)
{
	//checking if array is empty
	if (numitems == 0)
		std::cout << "List is empty.";
	//removing rocks from array
	else
	{
		numitems--;
		item = rocks[numitems];
	}
}