// C867 Class Roster
//
// Created by Kinsley Brown
//
#include <iostream>
#include "roster.h"
using namespace std;

int main()
{
    cout << "Course: C867 Scripting and Programming - Applications\n" << "Programming Language: C++\n" << "Student ID: #010127475\n" << "Name: Kinsley Brown" << std::endl << std::endl;

    // Data from student table
    const string studentData[] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
      "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
      "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
      "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
      "A5,Kinsley,Brown,kingsleybrownjr@yahoo.com,30,23,14,13,SOFTWARE"
    };

    // Sets array size
    const int studentDataTable = 5;
    // Creates repository using default parameterless constructor; Sets everything to default values
    Roster classRoster;

    // Display students
    for (int i = 0; i < studentDataTable; i++) classRoster.parse(studentData[i]);
    cout << "Displaying all students:" << std::endl;
    classRoster.printAll();
    cout << std::endl;
    
    // Display the students in the Software program
    cout << "Displaying all software students:" << std::endl;
    classRoster.printByDegreeType(SOFTWARE);
    cout << std::endl;

    // Display students with invalid email address based on format
    cout << "Displaying invalid email addess: " << std::endl;
    classRoster.printInvalidEmails();
    cout << std::endl;

    // Display the average number of days students spent in classes
    cout << "Displaying average days per class:" << std::endl;
    for (int i = 0; i < studentDataTable; i++)
    {
        classRoster.printAverageDays(classRoster.classRosterArray[i]->getStudentID());
    }
    cout << std::endl;

    // Remove student with ID of A3 and print all remaining students
    cout << "Remove student A3." << std::endl;
    classRoster.removeStudentByID("A3");
    cout << std::endl;
    
    // Throws error when student with an ID of A3 isn't found
    cout << "Remove student A3." << std::endl;
    classRoster.removeStudentByID("A3");
    cout << std::endl << std::endl;
}

/*
 F. Demonstrate the program’s required functionality by adding a main() function in main.cpp, which will contain the required function calls to achieve the following results:
 1. Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
 2. Create an instance of the Roster class called classRoster.
 3. Add each student to classRoster.
 4. Convert the following pseudo code to complete the rest of the main() function:
     classRoster.printAll();
     classRoster.printInvalidEmails();

 loop through classRosterArray and for each element:
 classRoster.printAverageDaysInCourse(current_object's student id);

 classRoster.printByDegreeProgram(SOFTWARE);
 classRoster.remove("A3");
 classRoster.printAll();
 classRoster.remove("A3");
 expected: the above line should print a message saying such a student with this ID was not found.
*/