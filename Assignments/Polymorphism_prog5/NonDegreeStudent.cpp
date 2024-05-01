#include "NonDegreeStudent.h"
#include <string>
using std::string;
using std::to_string;

NonDegreeStudent::NonDegreeStudent() : Student()  //init the inherited data
{
	//no new member data, but major is "NonDegree"
	Student::setmajor("NonDegree");
}

NonDegreeStudent::NonDegreeStudent(const string& fn, const string& ln, char mi,
	const string& title, float gpa, const string&)
	: Student(fn, ln, mi, title, gpa, "NonDegree")
{
}

NonDegreeStudent::NonDegreeStudent(const NonDegreeStudent& other) : Student(other)
{
	//no new member data, but major is "NonDegree"
	Student::setmajor("NonDegree");
}

//inherit getter methods from the parent
//inherit setter methods from the parent
//inherit toString from the parent

string NonDegreeStudent::isA() const
{
	return "NonDegree Student";
}