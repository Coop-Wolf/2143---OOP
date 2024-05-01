#pragma once
#include <string>
#include "Person.h"

using std::string;

class Student : public Person
{
public:
	//3 constructors: default, parameterized and the copy 
	Student();
	Student(const string&, const string&, char, const string&,
		float, const string&);
	Student(const Student&);
	~Student();

	//inherit getter methods from the parent
	//inherit setter methods from the parent

	//add getter methods
	float getGPA() const;
	string getmajor() const;
	string getStudentId() const;
	static int getNumStudents();  //shared method

	//add setter method
	void setGPA(float);
	void setmajor(const string&);

	//override parent toString method
	virtual string toString() const;

	//override parent isA method
	virtual string isA() const;

private:
	float gpa = 0.0;
	string major;
	string studentId;
	static int numStudents;  //shared variable
};


