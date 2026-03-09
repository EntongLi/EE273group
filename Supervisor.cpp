#include "Supervisor.h"
#include <sstream>

//Implements Supervisor constructor with initializer list and calls User constructor
Supervisor::Supervisor(const std::string& first_name, const std::string& last_name, const std::string& email, const std::string& department)
	: User(first_name, last_name), email(email), department(department) {
}

//Returns relevant role
std::string Supervisor::getRole() const {
	return "Supervisor";
}

//Builds the string to be returned by getDetails() using stringstream, including relevant supervisor info
std::string Supervisor::getDetails() const {
	std::ostringstream details;
	details << User::getDetails() << "\nRole: " << getRole() << "\nEmail: " << email << "\nDepartment: " << department;
	return details.str();
}