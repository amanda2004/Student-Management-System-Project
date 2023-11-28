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
    } else if(student_id > node->student_id) {
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
Student* StudentManagementSystem::addStudent(Student* node, string name, int student_id, string study_program, int cohort, float gpa, string date_of_birth, string phone_number) {
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
void StudentManagementSystem::addStudent(string name, int student_id, string study_program, int cohort, float gpa, string date_of_birth, string phone_number) {
    root = addStudent(root, name, student_id, study_program, cohort, gpa, date_of_birth, phone_number);
}

void StudentManagementSystem::editStudent(Student* node, int student_id) {
    while (node != nullptr) {
        if (student_id == node->student_id) {
            cout << "Enter new student name: ";
            cin.ignore();
            getline(cin, node->name);

            cout << "Enter new study program: ";
            getline(cin, node->study_program);

            cout << "Enter new student cohort: ";
            cin >> node->cohort;

            cout << "Enter new student GPA: ";
            cin >> node->gpa;

            cout << "Enter new date of birth: ";
            cin.ignore();
            getline(cin, node->date_of_birth);

            cout << "Enter new phone number: ";
            getline(cin, node->phone_number);

            cout << "Student information updated successfully." << endl;
            return;
        } else if (student_id < node->student_id) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    cout << "Student not found." << endl;
}

Student* StudentManagementSystem::chooseStudentToEdit() {
    int student_id;
    cout << "Enter the Student ID you want to edit: ";
    cin >> student_id;

    Student* studentToEdit = searchStudent(root, student_id);

    if (studentToEdit != nullptr){
        return studentToEdit;
    } else {
        return nullptr;
    }
}

void StudentManagementSystem::displayStudentsList() {
    if (head == nullptr) {
        cout << "No students in the system." << endl;
        return;
    }

    cout << "Student List:" << endl;
    cout << setw(15) << "Name" << setw(15) << "Student ID" << setw(15) << "Study Program" << setw(10) << "Cohort" << setw(10) << "GPA" << setw(15) << "Date of Birth" << setw(15) << "Phone Number" << endl;
    cout << setfill('-') << setw(90) << "" << setfill(' ') << endl;

    Student* current = head;
    while (current != nullptr) {
        cout << setw(15) << current->name << setw(15) << current->student_id << setw(15) << current->study_program << setw(10) << current->cohort << setw(10) << fixed << setprecision(2) << current->gpa << setw(15) << current->date_of_birth << setw(15) << current->phone_number << endl;
        current = current->next;
    }
}

void StudentManagementSystem::displayStudentsTree(Student* node) {
    if (node != nullptr) {
        displayStudentsTree(node->left);
        cout << setw(15) << node->name << setw(15) << node->student_id << setw(15) << node->study_program << setw(10) << node->cohort << setw(10) << fixed << setprecision(2) << node->gpa << setw(15) << node->date_of_birth << setw(15) << node->phone_number << endl;
        displayStudentsTree(node->right);
    }
}

Student* StudentManagementSystem::findMin(Student* node){
    while(node->left != nullptr){
        node = node->left;
    }
    return node;
}

Student* StudentManagementSystem::searchStudent(Student* node, int student_id){
    while (node != nullptr){
        if(student_id == node->student_id){
            cout << "Student found:" << endl;
            cout << setw(15) << "Name" << setw(10) << "Student ID" << setw(15) << "Study Program" << setw(10) << "Cohort" << setw(10) << "GPA" << setw(15) << "Date of Birth" << setw(15) << "Phone Number" << endl;
            cout << setfill('-') << setw(85) << "" << setfill(' ') << endl;
            cout << setw(15) << node->name << setw(10) << node->student_id << setw(15) << node->study_program << setw(10) << node->cohort << setw(10) << fixed << setprecision(2) << node->gpa << setw(15) << node->date_of_birth << setw(15) << node->phone_number << endl;
            return node;
        } else if (student_id < node->student_id) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    cout << "Student not found." << endl;
    return nullptr;
}

void StudentManagementSystem::displayStudents() {
    displayStudentsList();
    cout << endl;
    displayStudentsTree(root);
}

void StudentManagementSystem::editStudent() {
    Student* studentToEdit = chooseStudentToEdit();
    if (studentToEdit != nullptr) {
        editStudent(root, studentToEdit->student_id);
    }
}
