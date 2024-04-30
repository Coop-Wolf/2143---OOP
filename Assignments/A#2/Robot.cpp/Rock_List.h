//******************************************//
//	Header file for Rock_List class         //
//  This class creates an array of rocks    //
//  from the Rock class                     //
//******************************************//

#ifndef ROCK_LIST_H
#define ROCK_LIST_H
#include "Rock.h"


class Rock_List
{
public:

//Purpose:  This default constructor sets
//			the capacity to 100, creates
//			an array of 100 rocks and sets
//			nunitems to 0
//Receives: None
// 
//Returns:  None
Rock_List();

//Purpose:  This constructor sets the capacity
//			to value in parameter
//Receives: capacity
// 
//Returns:  None
Rock_List(int capacity);

//Purpose:  This constructor sets variables
//			to values stored in object
//Receives:	an object of Rock_List
// 
//Returns:  None
Rock_List(Rock_List& object);

//Purpose:	This destructor deletes the
//			dynamic array of rocks
//Recieves:	None
//
//Returns:	None
~Rock_List() { delete[] rocks; }

//Purpose:	Puts a rock into the array
//
//Recieves: Object of rock
//
//Returns:	None
void addrock(Rock& item);

//Prupose:	Returns the number of rocks
//			in the list
//Recieves:	None
//
//Returns:	number of rocks in list
int getnumitems() const;

//Purpose:	Removes rock from array
//
//Recieves:	A rock to remove
//
//Returns:	None
void remove_rock(Rock& item);

//Purpose:	Returns the rock at the given index
//
//Recieves:	index of rock
//
//Returns:	Rock
Rock getrock(const int i);

//Purpose:	Updates the rock list
//
//Recieves:	rock and index
//
//Returns:	None
void updatelist(Rock& rock, int i);

//Purpose:	Determines if array if full
//
//Recieves:	None
//
//Returns:	true or false
bool isfull() const { return numitems == capacity; };

//Purpose:	Determines if array if empty
//
//Recieves:	None
//
//Returns:	true or false
bool isempty() const { return numitems == 0; };

private:
	//array of class rocks
	Rock* rocks;
	int capacity, numitems;
};
#endif