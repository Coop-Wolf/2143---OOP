#pragma once
#include <string>
#include "Student.h"

using std::string;

class GraduateStudent : public Student
{
public:
	//3 constructors: default, parameterized and the copy 
	GraduateStudent();
	GraduateStudent(const string&, const string&, char, const string&,
		float, const string&, const string&, const string&);
	GraduateStudent(const GraduateStudent&);
	~GraduateStudent();

	//inherit getter methods from the parent
	//inherit setter methods from the parent

	//add getter methods
	string getTopic();
	string getAdvisor();

	//add setter method
	void setTopic(const string&);
	void setAdvisor(const string&);

	//override parent toString method
	virtual string toString() const;

	//override parent isA method
	virtual string isA() const;

	//add another method
	void EarnPhD();

private:
	string diss_topic;
	string thesis_advisor;
};