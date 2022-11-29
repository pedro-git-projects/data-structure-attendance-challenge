import { AttendanceList } from "./modules/attendanceList.js"
import { Student } from "./modules/student.js";

const separator = () => console.log("------------------------------------");

/* Creating students */
const pedro = new Student("Pedro", [10.0, 9.4], "A");
const alisson = new Student("Alisson", [10.0, 9.4], "A");
const ana = new Student("Ana", [10.0, 9.8], "A");

/* Creating attendanceList */ 
let chamada = new AttendanceList(pedro);
chamada.printList();
separator();

/* Inserting by index */
chamada.insert(0, ana);
chamada.printList();
separator();

/* Removing by index */
chamada.remove(1);
chamada.printList();
separator();

chamada.push(alisson);
chamada.printList();
separator();

/* Ordering by ascending grades */
chamada.orderByGrade();
chamada.printList();
separator();

const inactive = new Student("inacative", [0.0, 0.0], "I");
chamada.push(inactive);
chamada.printList();
separator();

/* Printing only active students */
chamada.printActiveList();

for(let i = 0; i < 42; i++) {
	chamada.push(pedro);
}

/* Showing the excceeding elements were not pushed into the attandance list */
console.log(chamada.length);
