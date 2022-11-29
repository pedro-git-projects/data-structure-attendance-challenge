#ifndef LINKED_LIST_H 
#define LINKED_LIST_H 

#include "node.h"
#include <iostream>

template<typename L>
struct LinkedList {
	protected:
		Node<L>* head;
		Node<L>* tail;
		int length;
	public:
		LinkedList(L value) {
			Node<L>* newNode = new Node{value};
			head = newNode;
			tail = newNode;
			length = 1;
		}

		~LinkedList() {
			if(head) delete head;
		}

		void printList() const {
			Node<L>* temp{head};
			while (temp != nullptr) { 
				std::cout << temp->value << std::endl;
				temp = temp->next;
			}
		}

		void append(L value) {
			Node<L>* newNode = new Node{value};
			if(head != nullptr) {
				tail->next = newNode;
				tail = newNode;
			} else {
				head = newNode; 
				tail = newNode;
			}
			length++;
		}

		void prepend(L value){
			Node<L>* newNode = new Node{value};
			if(head != nullptr) {
				newNode->next = head;
				head = newNode;
			} else {
				head = newNode;
				tail = newNode;
			}
			length++;
		}

		void reverse() {
			Node<L>* temp{head};
			head = tail;
			tail = temp;

			Node<L>* after{temp->next};
			Node<L>* before{nullptr};

			for(int i = 0; i < length; i++) {
				after = temp->next; 
				temp->next = before; 
				before = temp;
				temp = after;
			}		
		}

		Node<L>* removeFirst() {
			if(length == 0) return nullptr;

			Node<L>* desired{head};	
			head = head->next;	
			desired->next = nullptr; 
			length--;

			if(length == 0)	tail = nullptr;

			return desired;
		}

		Node<L>* removeLast() {
			if(length == 0)	return nullptr;

			Node<L>* desired{head};
			Node<L>* temp{head};
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

		Node<L>* remove(int index) {
			Node<L>* desired{LinkedList::getByIndex(index)};
			if(desired == nullptr) return nullptr;
			if(index == 0) return LinkedList::removeFirst();
			if(index == length - 1) return LinkedList::removeLast();

			Node<L>* prev{LinkedList::getByIndex(index -1)};
			Node<L>* temp{prev->next}; 
			prev->next = temp->next;
			temp->next = nullptr;
			length--;
			return temp;
		}

		Node<L>* getByIndex(int index) const {
			if(index < 0 || index >= length) {
				return nullptr;
			} else {
				Node<L>* desired{head};
				for(int i = 0; i != index; i++) {
					desired = desired->next;
				}
				return desired;
			}		
		}

		bool set(int index, L value) {
			Node<L>* desired{LinkedList::getByIndex(index)};
			if(desired != nullptr) {
				desired->value = value;
				return true;
			} else {
				return false;
			}		
		}

		bool insert(int index, L value) {
			Node<L>* desired{getByIndex(index)};
			if(desired == nullptr) return false;
			if(index == 0) {
				LinkedList::prepend(value);
				return true;
			} else if(index == length) {
				append(value);
				return true;
			}
			Node<L>* newNode = new Node{value};
			Node<L>* pre{ LinkedList::getByIndex(index -1) };
			newNode->next = pre->next;
			pre->next = newNode;
			length++;
			return true;
		}

		L getHead() const {
			return head->value;
		}

		L getTail() const {
			return tail->value;

		}

		int getLength() const {
			return length;
		}
};
#endif
