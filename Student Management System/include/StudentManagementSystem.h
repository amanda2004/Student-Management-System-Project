#ifndef STUDENTMANAGEMENTSYSTEM_H
#define STUDENTMANAGEMENTSYSTEM_H

#include "Student.h"
#include "User.h"
#include <string>

//Class for managing students using binary search tree and linked list
class StudentManagementSystem
{
    public:
        //Constructor
        StudentManagementSystem(const User& user);

        //Destructor to free memory
        ~StudentManagementSystem();

        //Wrapper function to remove a student
        void removeStudent(int student_id);

        //Getter function to access the root of the binary search tree
        Student* getRoot();

        //Wrapper function to add a student
        void addStudent(string name, int student_id, string study_program, int cohort, float gpa, string date_of_birth, string phone_number);

        //Wrapper function to edit a student's information
        void editStudent();

        void displayStudents();
        void clearTree(Student* node); //Function to clear all students from the binary search tree
        void clearList(); //Function to clear all students from the linked list
        void displayStudentsTable();
        User getCurrentUser() const;
        void setCurrentUser(const User& user);
        // Wrapper function to display all students sorted by ID
        void displayStudentsSortedByID();

    private:
        Student* root; //Root of the binary search tree
        Student* head; //Head of the linked list
        User currentUser;

        Student* addStudent(Student* node, string name, int student_id, string study_program, int cohort, float gpa, string date_of_birth, string phone_number); //Function to add a new student to the binary search tree
        Student* chooseStudentToEdit(); // Function to choose a student to edit
        Student* removeStudent(Student* node, int student_id); //Function to remove a student with a specific Student ID from the binary search tree
        Student* removeNode(Student* node); //Function to remove a node from the binary search tree
        Student* findMin(Student* node);
        Student* searchStudent(Student* node, int student_id);
        void displayStudentsList();
        void displayStudentsTree(Student* node);
        void editStudent(Student* node, int student_id);
        void displayStudentsTableHelper(Student* node, const int colWidths[]);
        // Function to sort students by ID using bubble sort
        void sortStudentsByID();


};

#endif // STUDENTMANAGEMENTSYSTEM_H
