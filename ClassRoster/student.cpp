// C867 Class Roster
//
// Created by Kinsley Brown
//
#include "student.h"
using namespace std;

// Empty constructor - set default values
Student::Student()
{
    // Pointers to variable names
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->studentEmail = "";
    this->studentAge = 0;
    // Loops over daysToComplete array and sets default days to 0
    for (int i = 0; i < daysArraySize; i++) this->daysToComplete[i] = 0;
    // Sets default degree type to SECURITY
    this->degreeType = DegreeType::SECURITY;
}

// Full constructor
Student::Student(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int daysToComplete[], DegreeType degreeType)
{
    
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->studentEmail = studentEmail;
    this->studentAge = studentAge;
    for (int i = 0; i < daysArraySize; i++) this->daysToComplete[i] = daysToComplete[i];
    this->degreeType = degreeType;
}

// Always write a destructor even when it does nothing because nothing is create dynamically, always good to have though.
Student::~Student() {}

// Getters
string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getStudentEmail() { return this->studentEmail; }
int Student::getStudentAge() { return this->studentAge; }
// Array is a pointer, to avoid returning the days individually, instead a reference to them
int* Student::getDaysToComplete() { return this->daysToComplete; }
DegreeType Student::getDegreeType() { return this->degreeType; }

// Setters
void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string fName) { this->firstName = firstName; }
void Student::setLastName(string lName) { this->lastName = lastName; }
void Student::setStudentEmail(string email) { this->studentEmail = studentEmail; }
void Student::setStudentAge(int age) { this->studentAge = studentAge; }
// Set each number of days individually
void Student::setDaysToComplete(int daysToComplete[])
{
    for (int i = 0; i < daysArraySize; i++) this->daysToComplete[i] = daysToComplete[i];
}
void Student::setDegreeType(DegreeType degreeType) { this->degreeType = degreeType; }

// Prints header to categorize data
void Student::printHeader()
{
    cout << left << setw(5) << "ID";
    cout << left << setw(15) << "First";
    cout << left << setw(15) << "Last";
    cout << left << setw(35) << "Email Address";
    cout << left << setw(8) << "Age";
    cout << left << setw(15) << "Days To Complete ";
    cout << left << setw(10) << "Degree" << endl;
}

void Student::print()
{
    cout << left << setw(5) << this->getStudentID();
    cout << left << setw(15) << this->getFirstName();
    cout << left << setw(15) << this->getLastName();
    cout << left << setw(35) << this->getStudentEmail();
    cout << left << setw(10) << this->getStudentAge();
    // Grab days individually
    cout << left << setw(5) << this->getDaysToComplete()[0];
    cout << left << setw(5) << this->getDaysToComplete()[1];
    cout << left << setw(5) << this->getDaysToComplete()[2];
    // Used the string version of degree type to display to screen
    cout << left << setw(10) << degreeTypeStrings[this->getDegreeType()] << '\n';
}

/*
 2. Create each of the following functions in the Student class:
 a. An accessor (i.e., getter) for each instance variable from part D1
 b. A mutator (i.e., setter) for each instance variable from part D1
 c. All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.
 d. Constructor using all of the input parameters provided in the table
 e. print() to print specific student data
 */