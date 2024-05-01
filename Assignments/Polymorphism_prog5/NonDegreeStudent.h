#pragma once
#include <string>
#include "Student.h"

using std::string;

class NonDegreeStudent : public Student
{
public:
	//3 constructors: default, parameterized and the copy 
	NonDegreeStudent();
	NonDegreeStudent(const string&, const string&, char, const string&,
		float, const string&);
	NonDegreeStudent(const NonDegreeStudent&);
	~NonDegreeStudent() {};

	//inherit getter methods from the parent
	//inherit setter methods from the parent
	//inherit parent toString method

	//override parent isA method
	string isA() const;
};