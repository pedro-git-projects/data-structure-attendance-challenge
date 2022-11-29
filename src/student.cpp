#include "student.h"
#include <ctime>
#include <ios>
#include <string>
#include <sstream>
#include <iomanip>

Student::Student(std::string name, std::string registrationCode, std::vector<float> grades, bool active):
	name{name}, registrationCode{registrationCode}, grades{grades}, active{active} {};

std::string Student::getName() const {
	return name;
};

std::string Student::getRegistration() const {
	return registrationCode; 
};

std::vector<float> Student::getGrades() const {
	return grades;
};

bool Student::isActive() const {
	return active;
};


std::ostream& operator<< (std::ostream& os, const Student& s) {
	std::string acc{};
	auto name{s.getName()};
	auto registration{s.getRegistration()};
	auto grades{s.getGrades()};
	auto active{Utils::boolToInt(s.isActive())};

	
	acc += ("student: " + name);
	acc += "\n";
	acc += ("registration: " + registration);
	acc += "\n";
	acc += ("active: " + active);
	acc += "\n";
	acc += "grades: [  ";
	for(auto grade : grades) {
		std::stringstream stream;
		stream << std::fixed << std::setprecision(2) << grade;
		auto current = stream.str();
		acc += current;
		acc += " ";
	}
	acc += " ]";

	os << acc;
	return os;
};
