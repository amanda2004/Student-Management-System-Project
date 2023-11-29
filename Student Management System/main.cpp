#include <iostream>
#include <iomanip>
#include "StudentManagementSystem.h"

using namespace std;

// Function to search for a student by ID and display the information
void searchStudent(Student* node, int student_id) {
    // Set column widths
    const int colWidths[] = {25, 20, 20, 10, 8, 18, 11};

    while (node != nullptr) {
        if (student_id == node->student_id) {
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
    bool isUserSignedIn = false;

    User currentUser("", ""); // Empty user for now
    StudentManagementSystem system(currentUser);

    // Authentication logic
    cout << "\n----------------------------------------------------------------------------------------------------------"
            "\n----------------------------------------------------------------------------------------------------------"
            "\n==============================Welcome to the Student Management System!==================================="
         << endl;
    cout << "Please sign in or register:" << endl;

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
                    if (!isUserSignedIn) {
                        currentUser.login();
                        isUserSignedIn = true;
                        cout << "Sign-in successful!" << endl;
                        break; // Break out of the loop on successful sign-in
                    } else {
                        cout << "User is already logged in. Please sign-out first." << endl;
                    }
                    break;
                } else {
                    cout << "Authentication failed. Please try again." << endl;
                }
            } while (true); // Loop until successful sign-in
        } else if (user_choice == 2) {
            cout << "Enter a new username: ";
            cin >> input_username;

            cout << "Enter a new password: ";
            cin >> input_password;

            //Assuming User constructor initializes isLoggedIn to false
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
