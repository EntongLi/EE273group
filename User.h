#pragma once
#include <string>

class User {
//Name is protected so it can be called but not edited by Student/Supervisor
protected:
	std::string first_name;
	std::string last_name;
public:
//Necessary constructor/destructor
	explicit User(const std::string& first_name, const std::string& last_name);
	virtual ~User() = default;

//Const = 0 to make this function pure virtual, unable to be instantiated
	virtual std::string getRole() const = 0;
	virtual std::string getDetails() const;
};