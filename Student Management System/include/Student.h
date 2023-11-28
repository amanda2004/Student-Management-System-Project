#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Student
{
    public:
        string name;
        int student_id;
        string study_program;
        int cohort;
        float gpa;
        string date_of_birth;
        string phone_number;

        Student* left;
        Student* right;
        Student* next; //Linked list pointer

        Student();
        ~Student();
};

#endif // STUDENT_H
