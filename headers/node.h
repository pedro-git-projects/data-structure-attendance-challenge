#ifndef NODE_H
#define NODE_H

#include <string>
struct Node {
	std::string value;
	Node* next;
	Node(std::string value);
};
#endif
