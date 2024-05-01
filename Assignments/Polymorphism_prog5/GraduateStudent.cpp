#include "GraduateStudent.h"
#include <string>

using std::string;
using std::to_string;

GraduateStudent::GraduateStudent() : Student()  //init the inherited data
{
	//init the new member data

}

GraduateStudent::GraduateStudent(const string& fn, const string& ln, char mi,
	const string& title, float gpa, const string& course, const string& topic, const string& advisor)
	: Student(fn, ln, mi, title, gpa, course)
{
	//init the new member data
	this->diss_topic = topic;
	this->thesis_advisor = advisor;
}

GraduateStudent::GraduateStudent(const GraduateStudent& other) :Student(other)
{
	//init the new member data
	diss_topic = other.diss_topic;
	thesis_advisor = other.thesis_advisor;
}

GraduateStudent::~GraduateStudent()
{}

//inherit getter methods from the parent
//inherit setter methods from the parent

//add getter methods
string GraduateStudent::getTopic()
{
	return diss_topic;
}

string GraduateStudent::getAdvisor()
{
	return thesis_advisor;
}

//add setter method
void GraduateStudent::setTopic(const string& topic)
{
	diss_topic = topic;
}

void GraduateStudent::setAdvisor(const string& advisor)
{
	thesis_advisor = advisor;
}

//override parent toString method
string GraduateStudent::toString() const
{
	string s = Student::toString();
	s += "\nwith thesis advisor: " + thesis_advisor + " and dissertation topic: "
	     + diss_topic;
	return s;
}

string GraduateStudent::isA() const
{
	return "Graduate Student";
}

//add another method
void GraduateStudent::EarnPhD()
{
	modifyTitle("Dr.");
}