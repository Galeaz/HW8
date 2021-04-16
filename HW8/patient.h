// Participants: Gabriela Lopez
// Date: 04-15-21
// Description: Patient header

#pragma once

#include <string>
#include <iostream>
using namespace std;

class Patient
{
private:
	int priority;
	unsigned int checkedInTime;
	string name;
	int age;
	char gender;
	unsigned int admittedTime;
	string careUnit;
	static string ER_description[5];
public:

	//Precondition: create a patient object
	//Postcondition: initializes all patient components
	Patient();
	
	//Precondition: int value containing the time patient checked in
	//Postcondition: sets the time checked in
	void setCheckedInTime(unsigned int t);
	
	//Precondition: N/A
	//Postcondition: returns time patient checked in
	unsigned int getCheckedInTime() const;
	
	//Precondition: int value containing priority status from 1 to 5 (1 = fine, 5 = really bad)
	//Postcondition: sets priority
	void setPriority(int priority);
	
	//Precondition: N/A
	//Postcondition: returns patient priority
	int getPriority() const;
	
	//Precondition: a string of the name of patient
	//Postcondition: sets name
	void setName(string name);

	//Precondition: N/A
	//Postcondition: returns patient name
	string getName() const;
	
	//Precondition: an int for age of patient
	//Postcondition: sets age
	void setAge(int age);
	
	//Precondition: N/A
	//Postcondition: returns the age of patient
	int getAge() const;
	
	//Precondition: a char for the patient gender
	//Postcondition: sets gender
	void setGender(char gender);
	
	//Precondition: N/A
	//Postcondition: returns patient gender
	char getGender() const;
	
	//Precondition: comparison of patients priority(patient 1 < patient 2)
	//Postcondition: returns a bool if first patient has less priority than the other
	friend bool operator <(const Patient& P1, const Patient& P2); //key in priority queue

	//Precondition: patient object to print
	//Postcondition: prints all patient information
	friend ostream& operator<<(ostream& outs, const Patient& obj);
};