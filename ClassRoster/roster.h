// C867 Class Roster
//
// Created by Kinsley Brown
//
#pragma once
#include "student.h"
#ifndef roster_h
#define roster_h
#include <stdio.h>

class Roster
{
public:
    int lastIndex = -1;
    const static int studentDataTable = 5;
    Student* classRosterArray[studentDataTable]; 

public:
    // Pulls student data and creates student object in roster
    void parse(string studentData);
    void add(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int day1, int day2, int day3, DegreeType degreeType);
    void printAll();
    void printByDegreeType(DegreeType degreeType);
    void printInvalidEmails();
    // Print average days of each class
    void printAverageDays(string studentID);
    bool removeStudentByID(string studentID);
    // Destructor
    ~Roster();
};

#endif /* roster_h */