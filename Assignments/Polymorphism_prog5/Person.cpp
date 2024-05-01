#include "Person.h"

Person::Person()
{
	firstName = "";
	lastName = "";
	initial = ' ';
	title = "";
}

Person::Person(const string& fn, const string& ln, char mi, const string& title)
{
	firstName = fn;
	lastName = ln;
	initial = mi;
	this->title = title;
}

Person::Person(const Person& other)
{
	firstName = other.firstName;
	lastName = other.lastName;
	initial = other.initial;
	title = other.title;

}

Person::~Person()
{
}

//getter methods
string Person::getFirstName() const
{
	return firstName;
}

string Person::getLastName() const
{
	return lastName;
}

string Person::getTitle() const
{
	return title;
}

char Person::getInitial() const
{
	return initial;
}

//setter methods
void Person::modifyTitle(const string& title)
{
	this->title = title;
}

//format string of data 
string Person::toString() const
{
	string s = title + " " + firstName + " " + initial + ". " + lastName;
	return s;
}

string Person::isA() const
{
	return "Person";
}