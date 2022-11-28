#include "linked_list.h"

LinkedList::LinkedList(std::string value) {
	Node* newNode = new Node{value};
	head = newNode;
	tail = newNode;
	length = 1;
}

void LinkedList::printList() const {
	Node* temp{head};
	while (temp != nullptr) { 
		std::cout << temp->value;
		temp = temp->next;
	}
}

void LinkedList::append(std::string value) {
	Node* newNode = new Node{value};
	if(head != nullptr) {
		tail->next = newNode;
		tail = newNode;
	} else {
		head = newNode; 
		tail = newNode;
	}
	length++;
}

void LinkedList::prepend(std::string value) {
	Node* newNode = new Node{value};
	if(head != nullptr) {
		newNode->next = head;
		head = newNode;
	} else {
		head = newNode;
		tail = newNode;
	}
	length++;
}

void LinkedList::reverse() {
	Node* temp{head};
	head = tail;
	tail = temp;

	Node* after{temp->next};
	Node* before{nullptr};

	for(int i = 0; i < length; i++) {
		after = temp->next; 
		temp->next = before; 
		before = temp;
		temp = after;
	}
}

Node* LinkedList::removeLast() {
	if(length == 0)	return nullptr;

	Node* desired{head};
	Node* temp{head};
	while(temp->next != nullptr) {
		desired = temp;
		temp = temp->next;
	}
	tail = desired;
	tail->next = nullptr;
	length--;

	if(length == 0) {
		head = nullptr;
		tail = nullptr;
	}
	return desired;
}

Node* LinkedList::removeFirst() {
	if(length == 0) return nullptr;

	Node* desired{head};	
	head = head->next;	
	desired->next = nullptr; 
	length--;

	if(length == 0)	tail = nullptr;

	return desired;
}

Node* LinkedList::getByIndex(int index) const {
	if(index < 0 || index >= length) {
		return nullptr;
	} else {
		Node* desired{head};
		for(int i = 0; i != index; i++) {
			desired = desired->next;
		}
		return desired;
	}

}

Node* LinkedList::remove(int index) {
	Node* desired{LinkedList::getByIndex(index)};
	if(desired == nullptr) return nullptr;
	if(index == 0) return LinkedList::removeFirst();
	if(index == length - 1) return LinkedList::removeLast();

	Node* prev{LinkedList::getByIndex(index -1)};
	Node* temp{prev->next}; 
	prev->next = temp->next;
	temp->next = nullptr;
	length--;
	return temp;
}

bool LinkedList::set(int index, std::string value) {
	Node* desired{LinkedList::getByIndex(index)};
	if(desired != nullptr) {
		desired->value = value;
		return true;
	} else {
		return false;
	} 
}

bool LinkedList::insert(int index, std::string value) {
	Node* desired{getByIndex(index)};
	if(desired == nullptr) return false;
	if(index == 0) {
		LinkedList::prepend(value);
		return true;
	} else if(index == length) {
		append(value);
		return true;
	}
	Node* newNode = new Node{value};
	Node* pre{ LinkedList::getByIndex(index -1) };
	newNode->next = pre->next;
	pre->next = newNode;
	length++;
	return true;
}

std::string LinkedList::getHead() const {
	return head->value;
}

std::string LinkedList::getTail() const {
	return tail->value;
}

int LinkedList::getLength() const {
	return length;
}
