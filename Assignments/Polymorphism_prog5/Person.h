#pragma once
#include <string>
using std::string;

class Person
{
public:
	//3 constructors: default, parameterized and the copy 
	Person();
	Person(const string&, const string&, char, const string&);
	Person(const Person&);

	//virtual destructor
	virtual ~Person();

	//getter methods
	string getFirstName() const;
	string getLastName() const;
	string getTitle() const;
	char getInitial() const;

	//no setter methods

	//virtual - children can inherit the concept (override)
	virtual string  toString() const;
	virtual string isA() const;

protected:
	//showing a protected method - available to derived classes only
	void modifyTitle(const string&);

private:
	string firstName = "";
	string lastName = "";
	char initial = ' ';
	string title; //Mr. Mrs. Ms. Miss Dr.

};

