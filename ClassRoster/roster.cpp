// C867 Class Roster
//
// Created by Kinsley Brown
//
#include <string>
#include "roster.h"

// Parses each row provided
void Roster::parse(string studentData)
{
    // Returns the index when comma is found
    int rhs = studentData.find(',');
    // Takes substring before the comma and grabs the student ID
    string studentID = studentData.substr(0, rhs);
    // Continues pass first comma to the next
    int lhs = rhs + 1;
    rhs = studentData.find(',', lhs);
    // Takes substring before the 2nd comma and grabs the first name
    string firstName = studentData.substr(lhs, rhs - lhs);

    // This process continues on from here on
    lhs = rhs + 1;
    rhs = studentData.find(',', lhs);
    string lastName = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1; 
    rhs = studentData.find(",", lhs);
    string studentEmail = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1; 
    rhs = studentData.find(",", lhs);
    int studentAge = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1; 
    rhs = studentData.find(",", lhs);
    int day1 = stod(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int day2 = stod(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int day3 = stod(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    // Sets default degree type
    DegreeType degreeType = SECURITY;
    // Looks through substring and assigns the degree type based on given degree type in string
    if (studentData.at(lhs) == 'S' && studentData.at(lhs + 1) == 'E') degreeType = SECURITY;
    else if (studentData.at(lhs) == 'S' && studentData.at(lhs + 1) == 'O') degreeType = SOFTWARE;
    else if (studentData.at(lhs) == 'N') degreeType = NETWORK;

    add(studentID, firstName, lastName, studentEmail, studentAge, day1, day2, day3, degreeType);
}

// Add method combines strings and creates object in repository
void Roster::add(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int day1, int day2, int day3, DegreeType degreeType)
{
    // Places days back into an array for the constructor
    int dayArr[3] = { day1, day2, day3 };
    // Makes a new Student object; first index -1
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, studentEmail, studentAge, dayArr, degreeType);
}

// Display all students
void Roster::printAll()
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) Roster::classRosterArray[i]->print();
}

void Roster::printInvalidEmails()
{
    bool any = false;

    // Retreive student emails
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        string email = (classRosterArray[i]->getStudentEmail());
        // Checks to see if email is formatted correctly
        if ((email.find("@") == string::npos) || (email.find(" ") != string::npos) || (email.find(".") == string::npos))
        {
            any = true;
            // Prints invalid email address
            cout << email << ":" << classRosterArray[i]->getFirstName() << std::endl;
        }
    }
    // If all emails valid prints none
    if (!any) cout << "NONE" << std::endl;
    
}


void Roster::printAverageDays(string studentID)
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            // Add up days and divivde by number of course days provided.
            cout << studentID << ":";
            cout << (classRosterArray[i]->getDaysToComplete()[0] + classRosterArray[i]->getDaysToComplete()[1] + 
                classRosterArray[i]->getDaysToComplete()[2]) / 3 << std::endl;
        }
    }
}

// Display students matching degree type
void Roster::printByDegreeType(DegreeType degreeType)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::classRosterArray[i]->getDegreeType() == degreeType) classRosterArray[i]->print();
    }
    cout << std::endl;
}

// Remove student by given student ID
bool Roster::removeStudentByID(string studentID)
{
    bool foundStudent = false;
    // Loops through the roster by last index since index may differ
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            foundStudent = true;
            // Here we will swap place with last student,
            // Then move the pointer but not the data in memory
            if (i < studentDataTable - 1)
            {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[studentDataTable - 1];
                classRosterArray[studentDataTable - 1] = temp;
            }
            // The last student is hidden but not destroyed.
            Roster::lastIndex--;
        }
    }
    if (foundStudent)
    {
        cout << studentID << " Removed from roster." << std::endl << std::endl;
        // Displays each student minus the removed ones
        this->printAll();
    }
    else cout << studentID << ": Student with this ID is not found." << std::endl << std::endl;;
    return 0;
}

// Removes objects that are dynamically allocated; the repository creates objects dynamically and must be used to destroy
Roster::~Roster()
{
    cout << "Destructor called!" << std::endl << std::endl;
    for (int i = 0; i < studentDataTable; i++)
    {
        cout << "Removing student #" << i + 1 << std::endl;
        delete classRosterArray[i];
        // Set to nullptr so it's no longer pointed at that address otherwise it can crash the program
        classRosterArray[i] = nullptr;
    }
}

/*
 E. Create a Roster class (roster.cpp) by doing the following:
 1. Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
 2. Create a student object for each student in the data table and populate classRosterArray.
 a. Parse each set of data identified in the “studentData Table.”
 b. Add each student object to classRosterArray.
 3. Define the following functions:
 a. public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, 
    int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)  that sets the instance variables from part D1 and updates the roster.
 b. public void remove(string studentID)  that removes students from the roster by student ID. 
    If the student ID does not exist, the function prints an error message indicating that the student was not found.
 c. public void printAll() that prints a complete tab-separated list of student data in the provided format: 
    A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. 
    The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.
 d. public void printAverageDaysInCourse(string studentID)  that correctly prints a student’s average number of days in the three courses. 
    The student is identified by the studentID parameter.
 e. public void printInvalidEmails() that verifies student email addresses and displays all invalid email addresses to the user.

 Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').

 f. public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information for a degree program specified by an enumerated type
 */