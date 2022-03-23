#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"

class Roster {
private:
	int last = -1;
	const static int numStudents = 5;
	Student *classRosterArray[numStudents];

public:
	void read(string row);

	void add(string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		DegreeProgram degreeprogram);

	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram dp);
	~Roster();
};





#endif

