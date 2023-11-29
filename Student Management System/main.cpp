#include <iostream>
#include <iomanip>
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

int main() {
    string input_username;
    string input_password;

    // Authentication logic
    cout << "\n----------------------------------------------------------------------------------------------------------"
            "\n----------------------------------------------------------------------------------------------------------"
            "\n==============================Welcome to the Student Management System!==================================="
         << endl;
    cout << "Please sign in or register:" << endl;

    User currentUser("", ""); // Empty user for now
    StudentManagementSystem system(currentUser);

    while (true) {
        cout << "1. Sign In\n"
             << "2. Register\n"
             << "3. Exit\n";
        int user_choice;
        cout << "Enter your choice: ";
        cin >> user_choice;

        if (user_choice == 1) {
            do {
                cout << "Enter your username: ";
                cin >> input_username;

                cout << "Enter your password: ";
                cin >> input_password;

                if (currentUser.authenticate(input_username, input_password)) {
                    if (currentUser.login()) {
                        cout << "Sign-in successful!" << endl;
                        break; // Break out of the loop on successful sign-in
                    } else {
                        cout << "User is already logged in. Please sign-out first." << endl;
                    }
                } else {
                    cout << "Authentication failed. Please try again." << endl;
                }
            } while (true); // Loop until successful sign-in
        } else if (user_choice == 2) {
            cout << "Enter a new username: ";
            cin >> input_username;

            cout << "Enter a new password: ";
            cin >> input_password;

            currentUser = User(input_username, input_password);
            cout << "Registration successful! Please sign in again." << endl;
        } else if (user_choice == 3) {
            return 0;
        } else {
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    int choice;
    do {
        cout << "\n----------------------------------------------------------------------------------------------------------"
                "\n----------------------------------------------------------------------------------------------------------"
                "\n=================================STUDENT MANAGEMENT SYSTEM MENU==========================================="
                "\nWelcome! What do you want to do today?"
                "\n1. Add Student"
                "\n2. Edit Student"
                "\n3. Search Student"
                "\n4. Display Student"
                "\n5. Remove Student"
                "\n6. Sign Out and Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            // ... (existing cases)
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
