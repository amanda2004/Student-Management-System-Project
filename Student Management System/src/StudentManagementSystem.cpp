#include "StudentManagementSystem.h"

//Constructor
StudentManagementSystem::StudentManagementSystem(const User& user): root(nullptr), head(nullptr), currentUser(user) {}

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


Student* StudentManagementSystem::findMin(Student* node){
    while(node->left != nullptr){
        node = node->left;
    }
    return node;
}

Student* StudentManagementSystem::searchStudent(Student* node, int student_id){
    // Set column widths
    const int colWidths[] = {25, 20, 20, 10, 8, 18, 11};

    while (node != nullptr){
        if(student_id == node->student_id){
            cout << "Student found:" << endl;

            // Print header
            cout << setw(colWidths[0]) << left << "Name"
                 << setw(colWidths[1]) << left << "Student ID"
                 << setw(colWidths[2]) << left << "Study Program"
                 << setw(colWidths[3]) << left << "Cohort"
                 << setw(colWidths[4]) << left << "GPA"
                 << setw(colWidths[5]) << left << "Date of Birth"
                 << setw(colWidths[6]) << left << "Phone Number" << endl;

            // Print separator line
            cout << setfill('-') << setw(colWidths[0] + colWidths[1] + colWidths[2] + colWidths[3] + colWidths[4] + colWidths[5] + colWidths[6]) << "" << setfill(' ') << endl;

            // Print student information in a tabulated format
            cout << setw(colWidths[0]) << left << node->name
                 << setw(colWidths[1]) << left << node->student_id
                 << setw(colWidths[2]) << left << node->study_program
                 << setw(colWidths[3]) << left << node->cohort
                 << setw(colWidths[4]) << left << fixed << setprecision(2) << node->gpa
                 << setw(colWidths[5]) << left << node->date_of_birth
                 << setw(colWidths[6]) << left << node->phone_number << endl;

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



void StudentManagementSystem::editStudent() {

    Student* studentToEdit = chooseStudentToEdit();
    if (studentToEdit != nullptr) {
        editStudent(root, studentToEdit->student_id);
    }
}

void StudentManagementSystem::displayStudentsTable() {
    if (root == nullptr) {
        cout << "No students in the system." << endl;
        return;
    }
    // Set column widths
    const int colWidths[] = {25, 20, 20, 10, 8, 18, 11};

    // Print header
    cout << setw(colWidths[0]) << left << "Name"
         << setw(colWidths[1]) << left << "Student ID"
         << setw(colWidths[2]) << left << "Study Program"
         << setw(colWidths[3]) << left << "Cohort"
         << setw(colWidths[4]) << left << "GPA"
         << setw(colWidths[5]) << left << "Date of Birth"
         << setw(colWidths[6]) << left << "Phone Number" << endl;

    // Print separator line
    cout << setfill('-') << setw(colWidths[0] + colWidths[1] + colWidths[2] + colWidths[3] + colWidths[4] + colWidths[5] + colWidths[6]) << "" << setfill(' ') << endl;

    // Print student data
    displayStudentsTableHelper(root, colWidths);
}


void StudentManagementSystem::displayStudentsTableHelper(Student* node, const int colWidths[]) {
    if (node != nullptr) {
        displayStudentsTableHelper(node->left, colWidths);

        // Print student information in a tabulated format
        cout << setw(colWidths[0]) << left << node->name
             << setw(colWidths[1]) << left << node->student_id
             << setw(colWidths[2]) << left << node->study_program
             << setw(colWidths[3]) << left << node->cohort
             << setw(colWidths[4]) << left << fixed << setprecision(2) << node->gpa
             << setw(colWidths[5]) << left << node->date_of_birth
             << setw(colWidths[6]) << left << node->phone_number << endl;

        displayStudentsTableHelper(node->right, colWidths);
    }
}

User StudentManagementSystem::getCurrentUser() const {
    return currentUser;
}

void StudentManagementSystem::setCurrentUser(const User& user) {
    currentUser = user;
}

// Function to sort students by ID using bubble sort
void StudentManagementSystem::sortStudentsByID() {
    // Bubble sort implementation
    bool swapped;
    do {
        swapped = false;
        Student* current = head;
        Student* next = head->next;

        while (next != nullptr) {
            if (current->student_id > next->student_id) {
                // Swap the students
                swap(current->student_id, next->student_id);
                swap(current->name, next->name);
                swap(current->study_program, next->study_program);
                swap(current->cohort, next->cohort);
                swap(current->gpa, next->gpa);
                swap(current->date_of_birth, next->date_of_birth);
                swap(current->phone_number, next->phone_number);

                swapped = true;
            }

            current = next;
            next = next->next;
        }
    } while (swapped);
}

// Wrapper function to display all students sorted by ID
void StudentManagementSystem::displayStudentsSortedByID() {
    // Sort the students by ID before displaying
    sortStudentsByID();

    // Display the sorted students
    displayStudentsTable();
}
