export class Student  {
	constructor(name, grades, status) {
		this.name = name;
		this.grades= grades;
		this.status= status;
	}

	printStudent() {
		let cc = "[ ";
		for(let i = 0; i < this.grades.length; i++) {
			let grade = this.grades[i];
			cc += grade;
			if(i !== this.grades.length - 1) {
				cc += " - ";
			}
		} 
		console.log(`${this.name} ${cc}] ${this.status}`);
	}

	studentToString() {
		let cc = "[ ";
		for(let i = 0; i < this.grades.length; i++) {
			let grade = this.grades[i];
			cc += grade;
			if(i !== this.grades.length - 1) {
				cc += " - ";
			}
		} 
		return`${this.name} ${cc}] ${this.status}`;
	}

}
