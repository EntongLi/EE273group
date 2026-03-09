#include "User.h"
#include <sstream>

//implements User class constructor with initializer list
User::User(const std::string& first_name, const std::string& last_name)
	: first_name(first_name), last_name(last_name) {
}
//Builds the string to be returned by getDetails() using stringstream
std::string User::getDetails() const {
	std::ostringstream details;
	details << "Name: " << first_name << " " << last_name;
	return details.str();
}