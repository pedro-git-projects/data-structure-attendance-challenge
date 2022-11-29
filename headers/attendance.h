#ifndef ATTENDANCE_H 
#define ATTENDANCE_H 

#include "linked_list.h"
#include <string>

struct Attendance {
	const unsigned int MAX_SIZE = 40;
	LinkedList<std::string> lista;
	unsigned int size;
};

#endif
