#include "StudentManagementSystem.h"

//Constructor
StudentManagementSystem::StudentManagementSystem(): root(nullptr), head(nullptr) {}

//Destructor to free memory
StudentManagementSystem::~StudentManagementSystem()
{
    clearTree(root);
    clearList();
}

//Function to remove a student with a specific Student ID from binary search tree
Student* StudentManagementSystem::removeStudent(Student* node, int student_id){
    if(node == nullptr){
        cout << "Student not found." << endl;
        return nullptr;
    }

    if(student_id < node -> student_id){
        node -> left = removeStudent(node -> left, student_id);
    } else if {
        node -> right = removeStudent(node -> right, student_id);
    } else {
        //Node with the Student ID to be removed is found
        Student* temp = removeNode(node);
        cout << "Student removed successfully." << endl;
        return temp;
    }
    return node;
}

//Function to remove a node from the binary search tree
Student* StudentManagementSystem::removeNode(Student* node){
    if(node -> left == nullptr){
        Student* temp = node -> right;
        delete node;
        return temp;
    } else if(node -> right == nullptr){
        Student* temp = node -> left;
        delete node;
        return temp;
    }

    //Node has two children, find the successor (minimum value in the right subtree)
    Student* successor = findMin(node -> right);

    //Copy the successor's data to this node
    node -> name = successor -> name;
    node -> student_id = successor -> student_id;
    node -> study_program = successor -> study_program;
    node -> cohort = successor -> cohort;
    node -> gpa = successor -> gpa;
    node -> date_of_birth = successor -> date_of_birth;
    node -> phone_number = successor -> phone_number;

    //Remove the successor
    node -> right = removeStudent(node -> right, successor -> student_id);

    return node;
}

//Function to clear all students from the binary search tree
void StudentManagementSystem::clearTree(Student* node){
    if(node != nullptr){
        clearTree(node -> left);
        clearTree(node -> right);
        delete node;
    }
}

//Function to clear all students from the linked list
void StudentManagementSystem::clearList(){
    while(head != nullptr){
        Student* temp = head;
        head = head -> next;
        delete temp;
    }
}

//Wrapper function to remove a Student
void StudentManagementSystem::removeStudent(int student_id){
    root = removeStudent(root, student_id);
}

//Getter function to access the root of the binary search tree
Student* StudentManagementSystem::getRoot(){
    return root;
}

//Function to add a new student to the binary search tree
student* StudentManagementSystem::addStudent(string name, int student_id, string study_program, int cohort, float gpa, string date_of_birth, int phone_number) {
    if (node == nullptr) {
        node = new Student;
        node->name = name;
        node->student_id = student_id;
        node->study_program = study_program;
        node->cohort = cohort;
        node->gpa = gpa;
        node->date_of_birth = date_of_birth;
        node->phone_number = phone_number;
        node->left = node->right = nullptr;
        node->next = head;
        head = node;
        cout << "Student added successfully." << endl;
    } else if (student_id < node->student_id) {
        node->left = addStudent(node->left, name, student_id, study_program, cohort, gpa, date_of_birth, phone_number);
    } else if (student_id > node->student_id) {
        node->right = addStudent(node->right, name, student_id, study_program, cohort, gpa, date_of_birth, phone_number);
    } else {
        cout << "Student with the same ID already exists." << endl;
    }

    return node;
}

// Wrapper function to add a student
void StudentManagementSystem::addStudent(string name, int student_id, string study_program, int cohort, float gpa, string date_of_birth, int phone_number) {
    root = addStudent(root, name, student_id, study_program, cohort, gpa, date_of_birth, phone_number);
}
