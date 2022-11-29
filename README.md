# Algorithms and Data Structures :: Attendance List Challenge 

### Instructions:

Implement a list data strucutre in which you're able to sotre for each discipline:

- The student name

- The student grade 

- The student enrollement status 

With respect to the list, one must be to: 

- Insert and remove elements anywhere

- Sort the list in ascending order by grade

- Insert no more than 40 elements 

- Print only active users

### Solution:

#### C++

The project is organized into two main folders, **src** and **headers**, the first storing .cpp files and the second .h files. Explaining the headers is enough:

- node.h:

	Which defines a class template called Node. A node has a value of type T and a Node* to its next element.

	When constructed, value recieves the passed value and next recieves a nullptr. When the destructor is invoked, next is deleted if it is not null.

- linked_list.h:

	Defines a class template for linked lists. It has a generic type Node<T> pointer as head, another as tail and an integer length. Those members are protected because the child class AttendanceList needs to access them.

	When constructed the LinkedList will take a value of type L  and and create a new node pointer Node<L>*, then head and tail will point to that node and lenght will be ser to one. When the constructor is invoked, the head, if exists, is deleted.

	The LinkedList template has a lot of member functions, such as:
	```c++
	printList(); append(L value); preppend(L value); reverse(); removeFirst(); removeLast(); remove(int index); getByIndex(int index); set(int index, L value);
	```
	and so on.

- student.h:

	Defines the student struct. Its private members are the students name, registration code, grades vector and if the enrollement is active.

	It also defines an overload for the extraction operator <<

- attendance_list.h:

	Defines the AttendanceList. We do this via means of inheritance, extending a LinkedList<Student>. Note who we used a templated class from our linked list with our student object.

	To fulfill the challenge the attendance list introduces a MAX_SIZE constant and overrides the insert, remove, append, preppend and printList inherited functions.

	It also defines two totally new members, orderByGrade and printActive.

- utils.h:

	Defines the namespace Utils which contains two utility methods, boolToString and boolToStatus. Their name is self explanatory.

#### JS

The javascript version is roughly divided into two folders, the root folder, where we have the main.js and package.json files and the modules, where all written library code inhabits. The package.json is there simply to enable ES6 modules. So let's explain the modules files:


- node.js:

	Simply implements and exports the Node class, which has two properties, value, and next. When first constructed, next is intialized to null.

- linkedList.js:

	Implements the LinkedList class, which has a head, tail and lenght. Here are also defined methods such as reverse, makeEmpty, push, pop, shift and unshift. Their implementation is almost identical to the C++ one, the method names are different simply to follow the JavaScript culture and nomenclature.

- student.js:

	Implements the student class, which has name, grade and status as well as print and toString methods.

- attendanceList.js:

	Implements the AttendanceList class, which extends LinkedList it adds the MAX_SIZE property. It also overrides the push, unshift, insert, remove and printList methods as well as adds the needed new methods for completing the challenge, orderByGrade and printActiveList.  

### Running the code

Clone the repository and navigate to the folder

```sh
$ git clone https://github.com/pedro-git-projects/data-structure-attendance-challenge; 
cd  data-strucutre-attendance-challenge
```

#### C++

If you're using a Unix system, there is a MakeFile with  **build**, **run**, **clean** and **index** recipes. The compiler being used for the recipe is *g++*, if you use another compiler, simply change the *CC* flag in the Makefile.

So once this is figured out simply:

```sh
make build; make run 
```

to run the project.

#### JS

To run the js version, make sure you have node installed and either run:

```js
node main.js
```

or 

```js
make run
```


