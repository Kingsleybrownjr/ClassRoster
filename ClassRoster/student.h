// C867 Class Roster
//
// Created by Kinsley Brown
//
#ifndef student_h
#define student_h
#pragma once
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "degree.h"
using std::string;
using std::cout;

class Student
{
public:
    // Created a constant for the size of the array, each student has 3 days  
    const static int daysArraySize = 3;

// This is accessible to this object only
private:
    string studentID;
    string firstName;
    string lastName;
    string studentEmail;
    int studentAge;
    int daysToComplete[daysArraySize];
    DegreeType degreeType;

public:
    // Empty constructor - sets to default values 
    Student();
    // Full constructor
    Student(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int daysToComplete[], DegreeType degreeType);
    // Destructor
    ~Student();

    // Getters
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getStudentEmail();
    int getStudentAge();
    int* getDaysToComplete();
    DegreeType getDegreeType();

    // Setters
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setStudentEmail(string studentEmail);
    void setStudentAge(int studentAge);
    void setDaysToComplete(int daysToComplete[]);
    void setDegreeType(DegreeType degreeType);

    // Custom method used to display the header for the data provided
    static void printHeader();

    void print();
};

#endif /* student_h */

/*
 1. Create the class Student in the files student.h and student.cpp, which includes each of the following variables:
 • student ID
 • first name
 • last name
 • email address
 • age
 • array of number of days to complete each course
 • degree program
 */