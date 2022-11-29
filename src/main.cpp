#include <linked_list.h>
#include "student.h"
#include <iostream>

int main() {
	Student pedro{"Pedro", "123", std::vector<float>{9.7, 8.0}, true};
	Student alisson{"Alisson", "123", std::vector<float>{9.7, 8.0}, true};

	LinkedList<Student>chamada{pedro};
	chamada.append(alisson);
	chamada.printList(); std::cout << std::endl;
}
