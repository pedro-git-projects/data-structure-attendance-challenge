import { LinkedList } from "./linkedList.js";
import { Node } from "./node.js";
import {Student} from "./student.js";

export class AttendanceList extends LinkedList {
	MAX_SIZE = 40;
	constructor(value) {
		super(value);
	}

	push(value) {
		if(this.length >= this.MAX_SIZE) { 
			console.log("Exceeded maximum list size");
			return;
		}
		const newNode = new Node(value);
		if(!this.head) {
			this.head = newNode;
			this.tail = newNode;
		} else {
			this.tail.next = newNode;
			this.tail = newNode;
		}
		console.log(`${newNode.value.name} pushed into list`);
		this.length++;
		return this;
	}

	unshift(value) {
		if(this.length >= this.MAX_SIZE) { 
			console.log("Exceeded maximum list size");
			return;
		}
		const newNode = new Node(value);
		if(!this.head) {
			this.head = newNode;
			this.tail = newNode;
		} else {
			newNode.next = this.head;
			this.head = newNode;
		}
		console.log(`${newNode.value.name} unshifted into list`);
		this.length++;
		return this;
	}

	insert(index, value) {
		if(this.length >= this.MAX_SIZE) { 
			console.log("Exceeded max length!");
			return false;
		}

		if(index < 0 || index > this.length) {
			console.log("index out of bounds");
			return false;
		}

		if(index === this.length) return this.push(value);
		if(index === 0) return this.unshift(value);

		const newNode = new Node(value);
		const temp = this.get(index - 1);
		newNode.next = temp.next;
		temp.next = newNode;

		this.length++;
		console.log(`${newNode.value.name} inserted in position ${index}`);
		return true;
	}

	remove(index) {
		if(index < 0 || index >= this.length) {
			console.log("index out of bounds");
			return undefined;
		}
		if(index === 0) return this.shift();
		if(index === this.length - 1) return this.pop();

		const before = this.get(index - 1);
		const temp = before.next;

		before.next = temp.next;
		temp.next = null;

		this.length--;
		console.log(`${temp.value.name} removed from position ${index}`);
		return temp;
	}

	orderByGrade() {
		let current = this.head;
		let index = new Student(); 
		let temp = new Student();
		if(!current) {
			return;
		} else {
			while(current !== null) {
				index = current.next;
				while(index !== null) {
					let currentGrades = current.value.grades;
					let currentMean = currentGrades.reduce((partialSum, a) => partialSum + a, 0);
					let indexGrades = index.value.grades;
					let indexMean = indexGrades.reduce((partialSum, a) => partialSum + a, 0);
					if(currentMean > indexMean) {
						temp = current.value;
						current.value = index.value;
						index.value = temp;
					}
					index = index.next;
				}
				current = current.next;
			}
		} 

	}

	printList() {
		let temp = this.head;
		let index = 1;
		let acc = "";
		while (temp !== null) {
			acc = temp.value.studentToString();
			console.log(`${index} ${acc}`);
			index++;
			temp = temp.next;
		}
	}

	printActiveList() {
		let temp = this.head;
		let index = 1;
		let acc = "";
		while (temp !== null) {
			if(temp.value.status === "A") {
				acc = temp.value.studentToString();
				console.log(`${index} ${acc}`);
			}
			index++;
			temp = temp.next;
		}
	}
};
