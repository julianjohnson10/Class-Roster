#include "roster.h"

//class header function. Prints to top of console.
void PrintClassHeader() {
	cout << "Course Title: Scripting and Programming - Applications - C867" << endl;
	cout << "Language used: C++" << endl;
	cout << "Student ID: #XXXX" << endl;
	cout << "Name: Julian Johnson" << endl << endl;
};

int main() {
	//data to be added to classRosterArray;
	const string studentData[] = {

	  "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	  "A5,Julian,Johnson,xxxxx@wgu.edu,27,45,35,40,SOFTWARE"
	};

	const int numStudents = 5;
	Roster classRoster;
	
	PrintClassHeader();

	//for each item, parse data and add to classRosterArray.
	//read function contains the add function 
	for (int i = 0; i < numStudents; i++) { 
		classRoster.read(studentData[i]);
	}

	cout << "Listing all students in the roster: " << endl;
	classRoster.printAll(); cout << endl;

	cout << "Printing invalid email addresses: " << endl;
	classRoster.printInvalidEmails();  cout << endl;

	cout << "Printing average days in each course: " << endl;
	for (int i = 0; i < numStudents; i++) {
		classRoster.printAverageDaysInCourse(studentData[i]);
		break; //we need this to only run once, as it iterates through the data.
	}
	
	cout << "Listing students by the SOFTWARE degree program: " << endl;
	classRoster.printByDegreeProgram(SOFTWARE); cout << endl;

	classRoster.remove("A3");
	classRoster.printAll();
	cout << endl;

	classRoster.remove("A3");
	//the above line should print a message saying the student with ID A3 is not found, as it was already removed once.
	cout << endl;
}
