#include "attendance_list.h"
#include "student.h"
#include <linked_list.h>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <numeric>

int main() {
	/* creating students */
	Student pedro{"Pedro", "123", std::vector<float>{9.7, 8.0}, true};
	Student alisson{"Alisson", "123", std::vector<float>{10.0, 10.0}, true};
	Student joao{"João", "123", std::vector<float>{5.0, 2.0}, true};

	/* creating attendance_list */
	AttendanceList chamada{pedro};

	/* appending values */
	chamada.append(alisson);
	chamada.prepend(joao);
	/*printing list */
	chamada.printList(); std::cout << std::endl;
	std::cout << "------------------------------------------" << std::endl;

	/* sorting list by ascending grade */
	chamada.orderByGrade();
	chamada.printList(); std::cout << std::endl;
	std::cout << "------------------------------------------" << std::endl;

	/* inserting using index */
	Student ana{"Ana", "123", std::vector<float>{1.0, 10.0}, true};
	chamada.insert(2, ana);
	chamada.printList(); std::cout << std::endl;
	std::cout << "------------------------------------------" << std::endl;

	/* sorting again */
	chamada.orderByGrade();
	chamada.printList(); std::cout << std::endl;
	std::cout << "------------------------------------------" << std::endl;


	/* testing for upper limit insertion */
	for(int i = 0; i < 41; i++) {
		chamada.append(alisson);
	}
	chamada.prepend(alisson);
	std::cout << chamada.getLength() << std::endl;
	std::cout << "------------------------------------------" << std::endl;
}
