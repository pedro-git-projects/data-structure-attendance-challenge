#ifndef ATTENDANCE_LIST_H 
#define ATTENDANCE_LIST_H 

#include "linked_list.h"
#include "student.h"
#include <string>

struct AttendanceList: public LinkedList<Student> {
	const int MAX_SIZE = 40;
	void append(Student s);
	void prepend(Student s);
	void orderByGrade();
	void printActive() const;
};
#endif
