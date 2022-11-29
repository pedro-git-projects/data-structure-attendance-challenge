#include <linked_list.h>
#include "attendance_list.h"
#include "student.h"
#include <iostream>
#include <stdexcept>
#include "attendance.h"

int main() {
	Student pedro{"Pedro", "123", std::vector<float>{9.7, 8.0}, true};
	Student alisson{"Alisson", "123", std::vector<float>{9.7, 8.0}, true};

	AttendanceList chamada{pedro};
	chamada.append(alisson);
	chamada.printList(); std::cout << std::endl;
	chamada.reverse();
	std::cout << std::endl;
	chamada.printList();
	std::cout << std::endl;

	for(int i = 0; i < 41; i++) {
		chamada.append(alisson);
	}
	std::cout << chamada.getLength();


}
