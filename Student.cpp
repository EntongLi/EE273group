#include "Student.h"
#include <sstream>

//Implements Student constructor with initializer list and calls User constructor 
Student::Student(const std::string& first_name, const std::string& last_name, long reg_num, int age, const std::string& degree)
	: User(first_name, last_name), reg_num(reg_num), age(age), degree(degree) {
}

//Returns relevant role
std::string Student::getRole() const {
	return "Student";
}

//Builds the string to be returned by getDetails() using stringstream, including relevant student info
std::string Student::getDetails() const {
	std::ostringstream details;
	details << User::getDetails() << "\nRole: " << getRole() << "\nRegistration Number: " << reg_num << "\nAge: " << age << "\nDegree: " << degree;
	return details.str();
}