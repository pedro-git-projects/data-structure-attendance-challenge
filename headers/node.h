#ifndef NODE_H
#define NODE_H

template<typename T>
struct Node {
	T value;
	Node* next;

	Node(T value) {
		this->value = value;
		next = nullptr;
	}

	~Node() {
		if(value) delete value;
		if(next) delete next;
	}
};
#endif
