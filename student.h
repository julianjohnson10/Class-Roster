#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <iomanip>
#include "degree.h"

using namespace std;

class Student {
public:
	const static int daysToCompleteArray = 3;
	//FUNCTIONS
	//Getters
	string GetStudentID();
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	int GetAge();
	int* GetCourseDays();
	enum DegreeProgram GetDegreeProgram();

	//Setters
	void SetStudentID(string sID);
	void SetFirstName(string fName);
	void SetLastName(string lName);
	void SetEmailAddress(string eAddress);
	void SetAge(int sAge);
	void SetCourseDays(int daysToComplete[]);
	void SetDegreeProgram(DegreeProgram dp);
	
	Student(); //default constructor with no params
	Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysToComplete[], DegreeProgram degreeProgram);
	~Student(); //destructor
	
	void Print(); //Print function

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int studentAge;
	int daysToComplete[daysToCompleteArray];
	DegreeProgram degreeProgram;
};





#endif