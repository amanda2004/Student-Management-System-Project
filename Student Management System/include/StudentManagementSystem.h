#ifndef STUDENTMANAGEMENTSYSTEM_H
#define STUDENTMANAGEMENTSYSTEM_H
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Structure to represent a student
struct Student {
    string name;
    int student_id;
    string study_program;
    int cohort;
    float gpa;
    string date_of_birth;
    int phone_number;
    Student* left;
    Student* right;
    Student* next; //Linked list pointer
};

//Class for managing students using binary search tree and linked list
class StudentManagementSystem
{
    public:
        //Constructor
        StudentManagementSystem();

        //Destructor to free memory
        ~StudentManagementSystem();

    private:
        Student* root; //Root of the binary search tree
        Student* head; //Head of the linked list
};

#endif // STUDENTMANAGEMENTSYSTEM_H
