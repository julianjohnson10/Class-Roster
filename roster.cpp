#include "roster.h"

void Roster::read(string studentdata) {
	DegreeProgram dp = NETWORK;
	if (studentdata.at(studentdata.size() - 1) == 'K') {
		dp = NETWORK;
	}
	else if (studentdata.at(studentdata.size() - 1) == 'Y') {
		dp = SECURITY;
	}
	else if (studentdata.at(studentdata.size() - 1) == 'E') {
		dp = SOFTWARE;
	}

	int rhs = studentdata.find(","); //Search for comma
	string studentID = studentdata.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string firstName = studentdata.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string lastName = studentdata.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string emailAddress = studentdata.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int studentAge = stoi(studentdata.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int days1 = stoi(studentdata.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int days2 = stoi(studentdata.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int days3 = stoi(studentdata.substr(lhs, rhs - lhs));

	add(studentID, firstName, lastName, emailAddress, studentAge, days1, days2, days3, dp);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {

	int daysArray[3] = { daysInCourse1,daysInCourse2,daysInCourse3 };

	classRosterArray[++last] = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeprogram);
}

void Roster::remove(string studentID) {
	cout << "Removing student with ID: " << studentID << endl;
	bool valid = false;
	Roster::last = Roster::last--; //removes last line from array and reassigns
	for (int i = 0; i < numStudents - 1; ++i) {
		if (classRosterArray[i]->GetStudentID() == studentID) {
			valid = true;

			Student* temp = classRosterArray[i];			//assign temp ptr for arr[i]
			classRosterArray[i] = classRosterArray[i + 1];  //shifts everything up
			classRosterArray[i + 1] = temp;
		}
		else {
			valid = false;
		}
	}
	if (valid == false) {
		cout << "Could not find student with ID: " << studentID << endl;
	}
}

void Roster::printAll() {

	for (int i = 0; i <= Roster::last; ++i) {
		classRosterArray[i]->Print();
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	
	for (int i = 0; i <= Roster::last; i++) {
		
		cout << classRosterArray[i]->GetStudentID() << ": ";
		cout << (classRosterArray[i]->GetCourseDays()[0] + classRosterArray[i]->GetCourseDays()[1] + classRosterArray[i]->GetCourseDays()[2])/3 << endl;

	}
	cout << endl;
}

//Note: A valid email must include an at sign ('@') and period ('.') and should not include a space (' ').
void Roster::printInvalidEmails() {
	bool validemail = false;

	for (int i = 0; i <= Roster::last; i++) {

		string email = (classRosterArray[i]->GetEmailAddress()); 

		if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
			validemail = true;
			cout << "Invalid email address: " << email << endl;
		}
	}
	if (!validemail) {
		cout << "No invalid email addresses." << endl;
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i <= Roster::last; i++) {
		if (Roster::classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
			classRosterArray[i]->Print();
		}
	}
}

Roster::~Roster() {
	cout << "Ending program!" << endl;
	cout << "Calling destructors:" << endl;
	for (int i = 0; i < numStudents; i++) {
		cout << "Removing student #" << i + 1 << endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}
