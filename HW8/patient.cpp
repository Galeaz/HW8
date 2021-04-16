// Participants: Gabriela Lopez
// Date: 04-15-21
// Description: Patient implementation

#include "patient.h"

Patient::Patient()
{
	checkedInTime;
	priority = 0;
	name = "unknown";
	age = 0;
	gender = 'u';
}

void Patient::setCheckedInTime(unsigned int t)
{
	this->checkedInTime = t;
}

unsigned int Patient::getCheckedInTime() const
{
	return checkedInTime;
}

void Patient::setPriority(int priority)
{
	this->priority = priority;
}

int Patient::getPriority() const
{
	return priority;
}

void Patient::setName(string name)
{
	this->name = name;
}

string Patient::getName() const
{
	return name;
}

void Patient::setAge(int age)
{
	this->age = age;
}

int Patient::getAge() const
{
	return age;
}

void Patient::setGender(char gender)
{
	this->gender = gender;
}

char Patient::getGender() const
{
	return gender;
}

bool operator <(const Patient& P1, const Patient& P2)
{
	return P1.priority < P2.priority;
}

string Patient::ER_description[5] =
{
	"Stable, with no resources anticipated or prescriptions",
	"Stable, with only one type of resource anticipated " ,
	"Stable, with multiple types of resources needed to investigate or treat",
	"High risk of deterioration, or signs of a time-critical problem",
	"Immediate, life-saving intervention required without delay"
};

ostream& operator <<(ostream& outs, const Patient& obj)
{
	outs << "ER level: " << obj.getPriority() << " - " << obj.ER_description[obj.getPriority() - 1] << '\n';
	outs << "\t\t\tChecked-In time: " << obj.getCheckedInTime() << '\n';
	outs << "\t\t\tPatient's name: " << obj.getName() << '\n';
	outs << "\t\t\tPatient's age: " << obj.getAge() << '\n';
	outs << "\t\t\tPatient's gender: " << obj.getGender() << '\n';
	return outs;
}