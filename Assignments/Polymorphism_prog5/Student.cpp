#include "Student.h"
#include <string>
#include <sstream>
#include <iomanip>

using std::string;
using std::to_string;
using std::fixed;
using std::setprecision;
using std::stringstream;

int Student::numStudents = 0;  //initialization for your static data

Student::Student() : Person()  //init the inherited data
{
	//init the new member data
	gpa = 0.0;
	major = "";
	numStudents++;
	studentId = "M" + to_string(numStudents);
}

Student::Student(const string& fn, const string& ln, char mi,
	const string& title, float gpa, const string& course)
	: Person(fn, ln, mi, title)
{
	//init the new member data
	this->gpa = gpa;
	major = course;
	numStudents++;
	studentId = "M" + to_string(numStudents);
}

Student::Student(const Student& other) :Person(other)
{
	//init the new member data
	this->gpa = other.getGPA();
	major = other.major;
	studentId = other.studentId;
	//don't think you want to increment numStudents here, since it is a copy
}

Student::~Student()
{
	numStudents--;
}

//inherit getter methods from the parent
//inherit setter methods from the parent

//add getter methods
float Student::getGPA() const
{
	return gpa;
}

string Student::getmajor() const
{
	return major;
}

string Student::getStudentId() const
{
	return studentId;
}

int Student::getNumStudents()
{
	return numStudents;
}

//add setter method
void Student::setGPA(float gpa)
{
	this->gpa = gpa;
}

void Student::setmajor(const string& course)
{
	major = course;
}

//override parent toString method
string Student::toString() const
{
	//string s = getTitle() + " " + getFirstName() + " " + getInitial() +
	//	". " + getLastName();

	//converting float to string
	stringstream stream;
	stream << fixed << setprecision(1) << gpa;
	string s_gpa = stream.str();

	string s = Person::toString();
	s += " with id: " + studentId + " gpa: " + s_gpa +
		" course: " + major + " ";
	return s;
}

string Student::isA() const
{
	return "Student";
}