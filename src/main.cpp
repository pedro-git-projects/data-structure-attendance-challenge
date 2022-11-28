#include <linked_list.h>
#include <iostream>

int main() {
	LinkedList ll{"1"};
	ll.printList(); std::cout << "\n";

	ll.append("2");
	ll.printList(); std::cout << "\n";


	ll.prepend("0");
	ll.printList(); std::cout << "\n";

	ll.reverse();
	ll.printList(); std::cout << "\n";
}
