#include "attendance_list.h"
#include "node.h"
#include "student.h"
#include <numeric>

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


void AttendanceList::prepend(Student student){
	Node<Student>* newNode = new Node{student};
	if(length >= MAX_SIZE) {
		std::cout << "Exceeded max length!" << std::endl;
		return;
	}
	if(head != nullptr) {
		newNode->next = head;
		head = newNode;
	} else {
		head = newNode;
		tail = newNode;
	}
	length++;
};

void AttendanceList::orderByGrade() {
	Node<Student>* current{head};
	Node<Student>* index{};
	Student temp{};
	if(!head) { 
		return;
	} else {
		while (current != nullptr) {
			index = current->next;
			while (index != nullptr) {
				auto currentGrades = current->value.getGrades();
				auto currentMean = std::reduce(currentGrades.begin(), currentGrades.end());
				auto indexGrades = index->value.getGrades();
				auto indexMean = std::reduce(indexGrades.begin(), indexGrades.end());
				if(currentMean > indexMean) {
					temp = current->value;
					current->value = index->value;
					index->value = temp;
				}
				index = index->next;
			}
			current = current->next;
		}
	}
};
