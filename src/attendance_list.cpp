#include "attendance_list.h"
#include "node.h"
#include "student.h"
#include <numeric>
#include <string>
#include <sstream>
#include <iomanip>

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
	std::cout << newNode->value.getName() << " appended" << std::endl;
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
	std::cout << newNode->value.getName() << " prepended" << std::endl;
	length++;
};


bool AttendanceList::insert(int index, Student s) {
	Node<Student>* desired{getByIndex(index)};
	if(desired == nullptr) return false;
	if(index == 0) {
		LinkedList::prepend(s);
		return true;
	} else if(index == length) {
		append(s);
		return true;
	}
	Node<Student>* newNode = new Node{s};
	Node<Student>* pre{ LinkedList::getByIndex(index -1) };
	newNode->next = pre->next;
	pre->next = newNode;
	length++;
	std::cout << newNode->value.getName() << " added to position " << std::to_string(index) << std::endl;
	return true;
}


Node<Student>* AttendanceList::remove(int index) {
	Node<Student>* desired{LinkedList::getByIndex(index)};
	if(desired == nullptr) return nullptr;

	if(index == 0) { 
		std::cout << desired->value.getName() << " removed from position " << index << std::endl; 
		return LinkedList::removeFirst(); 
	}

	if(index == length - 1) { 
		std::cout << desired->value.getName() << " removed from position " << index << std::endl; 
		return LinkedList::removeLast();
	}

	Node<Student>* prev{LinkedList::getByIndex(index -1)};
	Node<Student>* temp{prev->next}; 
	prev->next = temp->next;
	temp->next = nullptr;
	length--;
	std::cout << desired->value.getName() << " removed from position " << index << std::endl; 
	return temp;
}


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

void AttendanceList::printList() const {
	Node<Student>* temp{head};
	int index{1};
	std::string index_str{};
	while (temp != nullptr) { 
		index_str = std::to_string(index);
		std::cout << index_str << " " << temp->value << std::endl;
		index++;
		temp = temp->next;
	}
}


void AttendanceList::printActive() const {
	Node<Student>* temp{head};
	int index{1};
	std::string index_str{};
	while (temp != nullptr) { 
		if(temp->value.isActive()){
			index_str = std::to_string(index);
			std::cout << index_str << " " << temp->value << std::endl;
			index++;
		}
		temp = temp->next;
	}
}

