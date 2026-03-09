#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include "User.h"
#include "Student.h"
#include "Supervisor.h"

// Splits a CSV line into tokens by the given delimiter
std::vector<std::string> splitLine(const std::string& line, char delimiter = ',') {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream stream(line);
    while (std::getline(stream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Parses users.txt and returns a vector of polymorphic User pointers.
// Role is inferred from field count:
//   5 fields -> Student  (first, last, reg_num, age, degree)
//   4 fields -> Supervisor (first, last, email, department)
std::vector<std::unique_ptr<User>> loadUsers(const std::string& filename) {
    std::vector<std::unique_ptr<User>> users;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: could not open file '" << filename << "'\n";
        return users;
    }

    std::string line;
    int lineNumber = 0;

    while (std::getline(file, line)) {
        ++lineNumber;

        if (line.empty()) continue;

        std::vector<std::string> fields = splitLine(line);

        if (fields.size() == 5) {
            // Student: first, last, reg_num, age, degree
            try {
                long reg_num = std::stol(fields[2]);
                int age = std::stoi(fields[3]);
                users.push_back(std::make_unique<Student>(fields[0], fields[1], reg_num, age, fields[4]));
            }
            catch (const std::exception& e) {
                std::cerr << "Warning: could not parse Student on line " << lineNumber
                    << " (" << e.what() << ") — skipping\n";
            }
        }
        else if (fields.size() == 4) {
            // Supervisor: first, last, email, department
            users.push_back(std::make_unique<Supervisor>(fields[0], fields[1], fields[2], fields[3]));
        }
        else {
            std::cerr << "Warning: unrecognised format on line " << lineNumber << " (skipping)\n";
        }
    }

    return users;
}

int main() {
    const std::string filename = "users.txt";

    std::cout << "Loading users from '" << filename << "'...\n";
    std::vector<std::unique_ptr<User>> users = loadUsers(filename);

    if (users.empty()) {
        std::cout << "No users loaded. Exiting.\n";
        return 1;
    }

    // Count students and supervisors for the summary
    int studentCount = 0;
    int supervisorCount = 0;
    for (const auto& user : users) {
        if (user->getRole() == "Student")    ++studentCount;
        if (user->getRole() == "Supervisor") ++supervisorCount;
    }

    std::cout << "Successfully loaded " << users.size() << " user(s): "
        << studentCount << " student(s), "
        << supervisorCount << " supervisor(s).\n";
    std::cout << std::string(50, '=') << "\n\n";

    // Print all users grouped by role using polymorphism
    std::cout << "--- STUDENTS ---\n\n";
    for (const auto& user : users) {
        if (user->getRole() == "Student") {
            std::cout << user->getDetails() << "\n\n";
        }
    }

    std::cout << std::string(50, '=') << "\n\n";

    std::cout << "--- SUPERVISORS ---\n\n";
    for (const auto& user : users) {
        if (user->getRole() == "Supervisor") {
            std::cout << user->getDetails() << "\n\n";
        }
    }

    return 0;
}