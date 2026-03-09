#pragma once
#include "User.h"
#include <string>

//Declare Supervisor class that inherits from User
class Supervisor : public User {
private:
	std::string email;
	std::string department;
public:
	//Constructor to initialize the Supervisor class and call the User constructor
	Supervisor(const std::string& first_name, const std::string& last_name, const std::string& email, const std::string& department);
	//Overrides virtual functions from User class to return relevant role and details for Supervisor
	std::string getRole() const override;
	std::string getDetails() const override;
};