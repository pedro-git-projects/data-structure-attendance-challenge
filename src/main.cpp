#include <linked_list.h>
#include <iostream>

int main() {
	LinkedList<std::string> lls{"1"};
	lls.printList(); std::cout << std::endl;

	LinkedList<int> lli{1};
	lli.printList(); std::cout << std::endl;


	LinkedList<float> llf{1};
	llf.printList(); std::cout << std::endl;
}
