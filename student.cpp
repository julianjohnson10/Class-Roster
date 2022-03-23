#include "student.h"

using namespace std;

Student::Student() { //default constructor params
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->studentAge = 0;
	for (int i = 0; i < daysToCompleteArray; i++) {
		this->daysToComplete[i] = 0;
	}
	this->degreeProgram = DegreeProgram::NETWORK;

	return;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysToComplete[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->studentAge = studentAge;
	for (int i = 0; i < daysToCompleteArray; i++) {
		this->daysToComplete[i] = daysToComplete[i];
	}
	this->degreeProgram = degreeProgram;
}

Student::~Student() { //destructor

}


string Student::GetStudentID() {
	return this->studentID;
}

string Student::GetFirstName() {
	return this->firstName;
}

string Student::GetLastName() {
	return this->lastName;
}

string Student::GetEmailAddress() {
	return this->emailAddress;
}

int Student::GetAge() {
	return this->studentAge;
}

int* Student::GetCourseDays() {
	return this->daysToComplete;
}

DegreeProgram Student::GetDegreeProgram() {
	return this->degreeProgram;
}

void Student::SetStudentID(string sID) {
	this->studentID = sID;
}

void Student::SetFirstName(string fName) {
	this->firstName = fName;
}

void Student::SetLastName(string lName) {
	this->lastName = lName;
}

void Student::SetEmailAddress(string eAddress) {
	this->emailAddress = eAddress;
}

void Student::SetAge(int sAge) {
	this->studentAge = sAge;
}

void Student::SetCourseDays(int numdays[]) {
	
	for (int i = 0; i < daysToCompleteArray; i++) {

		this->daysToComplete[i] = numdays[i];
	
	}
}

void Student::SetDegreeProgram(DegreeProgram dp)
{
	this->degreeProgram = dp;
}

void Student::Print() {

	cout << this->GetStudentID() << '\t';
	cout << this->GetFirstName() << '\t';
	cout << this->GetLastName() << setw(4) << '\t';
	cout << this->GetEmailAddress() << setw(10) << '\t';
	cout << this->GetAge() << '\t';
	cout << this->GetCourseDays()[0] << ',' << " ";
	cout << this->GetCourseDays()[1] << ',' << " ";
	cout << this->GetCourseDays()[2] << '\t' << " ";
	cout << degreeProgramStrings[this->GetDegreeProgram()] << '\n';
}