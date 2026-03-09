#pragma once
#include "User.h"
#include <string>

//Declare Student class that inherits from User
class Student : public User {
private:
	long reg_num;
	int age;
	std::string degree;
public:
	//Constructor to initialize the Student class and call the User constructor
	Student(const std::string& first_name, const std::string& last_name, long reg_num, int age, const std::string& degree);
	//Overrides virtual functions from User class to return relevant role and details for Student
	std::string getRole() const override;
	std::string getDetails() const override;
};
