#include "attendance_list.h"
#include "student.h"
#include <stdexcept>

void AttendanceList::append(Student student) {
	Node<Student>* newNode = new Node{student};
	if(length >= MAX_SIZE) {
		std::cout << "Exceeded max length!" << std::endl;
		return;
	}
	if(head != nullptr) {
		tail->next = newNode;
		tail = newNode;
	} else {
		head = newNode; 
		tail = newNode;
	}
	length++;
};

