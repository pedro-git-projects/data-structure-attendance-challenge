#include "student.h"
#include "utils.h"
#include <ctime>
#include <ios>
#include <string>
#include <sstream>
#include <iomanip>


Student::Student() = default;

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
	auto active{Utils::booleanToStatus(s.isActive())};

	acc += (name); acc += " ";
	acc += "[  ";
	for(auto grade : grades) {
		std::stringstream stream;
		stream << std::fixed << std::setprecision(2) << grade;
		auto current = stream.str();
		acc += current;
		acc += " ";
	}
	acc += " ]"; acc += " ";
	acc += ( active);	

	os << acc;
	return os;
};

/*
 ************ this version was more complete, but I changed it to be more
 ************ similar to the example in the slide
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
*/
