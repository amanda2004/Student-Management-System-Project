#include <iostream>
#include "StudentManagementSystem.h"

using namespace std;

// Function to search for a student by ID and display the information
void searchStudent(Student* node, int student_id) {
    while (node != nullptr) {
        if (student_id == node->student_id) {
            cout << "Student found:" << endl;
            cout << setw(15) << "Name" << setw(10) << "Student ID" << setw(15) << "Study Program" << setw(10) << "Cohort" << setw(10) << "GPA" << setw(15) << "Date of Birth" << setw(15) << "Phone Number" << endl;
            cout << setfill('-') << setw(85) << "" << setfill(' ') << endl;
            cout << setw(15) << node->name << setw(10) << node->student_id << setw(15) << node->study_program << setw(10) << node->cohort << setw(10) << fixed << setprecision(2) << node->gpa << setw(15) << node->date_of_birth << setw(15) << node->phone_number << endl;
            return;
        } else if (student_id < node->student_id) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    cout << "Student not found." << endl;
}

int main()
{
    StudentManagementSystem system;

    int choice;
    do{
        cout << "\n----------------------------------------------------------------------------------------------------------"
                "\n----------------------------------------------------------------------------------------------------------"
                "\n=================================STUDENT MANAGEMENT SYSTEM MENU==========================================="
                "\nWelcome! What do you want to do today?"
                "\n1. Add Student"
                "\n2. Edit Student"
                "\n3. Search Student"
                "\n4. Display Student"
                "\n5. Remove Student"
                "\n6. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                {
                    string name;
                    int student_id;
                    string study_program;
                    int cohort;
                    float gpa;
                    string date_of_birth;
                    string phone_number;

                    cout << "Enter Student Name: ";
                    cin.ignore(); // Clear the buffer
                    getline(cin, name);

                    cout << "Enter Student ID: ";
                    cin >> student_id;

                    cout << "Enter Study Program: ";
                    cin.ignore(); //Clear the buffer
                    getline(cin, study_program);

                    cout << "Enter Student Cohort: ";
                    cin >> cohort;

                    cout << "Enter Student GPA: ";
                    cin >> gpa;

                    cout << "Enter Student Date Of Birth: ";
                    cin.ignore(); //Clear the buffer
                    getline(cin, date_of_birth);

                    cout << "Enter Student Phone Number: ";
                    getline(cin, phone_number);

                    system.addStudent(name, student_id, study_program, cohort, gpa, date_of_birth, phone_number);
                }
                break;

            case 2:
                system.editStudent();
                break;

            case 3:
                {
                    int student_id;
                    cout << "Enter the Student ID to search: ";
                    cin >> student_id;
                    searchStudent(system.getRoot(), student_id);
                }
                break;

            case 4:
                system.displayStudents();
                break;

            case 5:
                {
                    int student_id;
                    cout << "Enter the Student ID of the student you want to remove: ";
                    cin >> student_id;
                    system.removeStudent(student_id);
                }
                break;

            case 6:
                system.clearTree(system.getRoot());
                system.clearList();
                cout << "Exiting program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 6);

    return 0;
}
