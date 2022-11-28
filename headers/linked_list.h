#ifndef LINKED_LIST_H 
#define LINKED_LIST_H 
#include "node.h"
#include <iostream>
#include <string>

struct LinkedList {
	private:
		Node* head;
		Node* tail;
		int length;
	public:
		LinkedList(std::string value);
		void printList() const;
		void append(std::string value);
		void prepend(std::string value);
		void reverse();
		Node* removeFirst();
		Node* removeLast();
		Node* remove(int index);
		Node* getByIndex(int index) const;
		bool set(int index, std::string value);
		bool insert(int index, std::string value);
		std::string getHead() const;
		std::string getTail() const;
		int getLength() const;
};
#endif
