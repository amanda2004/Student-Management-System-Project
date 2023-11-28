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

        //Function to remove a student with a specific Student ID from the binary search tree
        Student* removeStudent(Student* node, int student_id);

        //Function to remove a node from the binary search tree
        Student* removeNode(Student* node);

        //Function to clear all students from the binary search tree
        void clearTree(Student* node);

        //Function to clear all students from the linked list
        void clearList();

        //Wrapper function to remove a student
        void removeStudent(int student_id);

        //Getter function to access the root of the binary search tree
        Student* getRoot();
        
        //Function to add a new student to the binary search tree
        Student* addStudent(Student* node, string name, int student_id, string study_program, int cohort, float gpa, string date_of_birth, int phone_number);
        
        //Wrapper function to add a student
        void addStudent(string name, int student_id, string study_program, int cohort, float gpa, string date_of_birth, int phone_number);

    private:
        Student* root; //Root of the binary search tree
        Student* head; //Head of the linked list
};

#endif // STUDENTMANAGEMENTSYSTEM_H
