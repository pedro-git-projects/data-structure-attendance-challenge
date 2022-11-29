#include <linked_list.h>
#include "attendance_list.h"
#include "student.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <numeric>
#include "attendance.h"

int main() {
	Student pedro{"Pedro", "123", std::vector<float>{9.7, 8.0}, true};
	Student alisson{"Alisson", "123", std::vector<float>{10.0, 10.0}, true};
	Student joao{"João", "123", std::vector<float>{5.0, 2.0}, true};

	AttendanceList chamada{pedro};
	chamada.append(alisson);
	chamada.append(joao);
	chamada.printList(); std::cout << std::endl;
	std::cout << "------------------------------------------" << std::endl;

	chamada.orderByGrade();
	chamada.printList(); std::cout << std::endl;

	/*

	for(int i = 0; i < 41; i++) {
		chamada.append(alisson);
	}
	chamada.prepend(alisson);
	//std::cout << chamada.getLength();

	std::vector<float>v{1, 2, 2};
	
	auto reduced = std::reduce(v.begin(), v.end());
	std::cout << reduced;
	*/
}
