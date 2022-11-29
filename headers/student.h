#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

struct Student {
		Student();
		Student(std::string name, std::string registrationCode, std::vector<float> grades, bool active);
		std::string getName() const;
		std::string getRegistration() const;
		std::vector<float> getGrades() const;
		std::string printGrades() const;
		bool isActive() const;
	private:
		std::string name;
		std::string registrationCode;
		std::vector<float> grades;
		bool active;
};

std::ostream& operator << (std::ostream& os, const Student& student);

#endif
