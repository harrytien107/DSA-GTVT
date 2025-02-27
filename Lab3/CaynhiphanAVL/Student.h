#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <algorithm>
using namespace std;

class Student
{
private:
    int studentID;
    string name;
    string dateOfBirth;
    float gpa;

public:
    // Constructors
    Student() : studentID(0), name(""), dateOfBirth(""), gpa(0.0) {}
    Student(int id, const string& n, const string& d, float g) :
        studentID(id), name(n), dateOfBirth(d), gpa(g) {}

    // Getters and Setters
    int GetStudentID() const { return studentID; }
    void SetStudentID(int id) { studentID = id; }
    const string& GetName() const { return name; }
    void SetName(const string& n) { name = n; }
    const string& GetDateOfBirth() const { return dateOfBirth; }
    void SetDateOfBirth(const string& d) { dateOfBirth = d; }
    float GetGPA() const { return gpa; }
    void SetGPA(float g) { gpa = g; }
};

#endif // STUDENT_H