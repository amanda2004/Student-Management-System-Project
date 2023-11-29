#include <iostream>
#include <iomanip>
#include "StudentManagementSystem.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif

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

// Function to clear the terminal screen
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    string input_username;
    string input_password;
    bool isUserSignedIn = false;

    User currentUser("", ""); // Empty user for now
    StudentManagementSystem system(currentUser);

    // Authentication logic
    cout << R"(
                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                                ~  _____ __  __  _____   ___   ___ ___  ____  ~
                                ~ / ____|  \/  |/ ____| |__ \ / _ \__ \|___ \ ~
                                ~| (___ | \  / | (___      ) | | | | ) | __) |~
                                ~ \___ \| |\/| |\___ \    / /| | | |/ / |__ < ~
                                ~ ____) | |  | |____) |  / /_| |_| / /_ ___) |~
                                ~|_____/|_|  |_|_____/  |____|\___/____|____/ ~
                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            )"
         << "\n-----------------------------------------------------------------------------------------------------------------"
         << "\n-----------------------------------------------------------------------------------------------------------------"
         << "\n=================================Welcome to the Student Management System!======================================="
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

                        int choice;
                        do {
                            clearScreen();
                            cout << R"(
                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                                ~  _____ __  __  _____   ___   ___ ___  ____  ~
                                ~ / ____|  \/  |/ ____| |__ \ / _ \__ \|___ \ ~
                                ~| (___ | \  / | (___      ) | | | | ) | __) |~
                                ~ \___ \| |\/| |\___ \    / /| | | |/ / |__ < ~
                                ~ ____) | |  | |____) |  / /_| |_| / /_ ___) |~
                                ~|_____/|_|  |_|_____/  |____|\___/____|____/ ~
                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            )"
                                    "\n-----------------------------------------------------------------------------------------------------------------"
                                    "\n-----------------------------------------------------------------------------------------------------------------"
                                    "\n=====================================STUDENT MANAGEMENT SYSTEM MENU=============================================="
                                    "\nWelcome! What do you want to do today?"
                                    "\n1. Add Student"
                                    "\n2. Edit Student"
                                    "\n3. Search Student"
                                    "\n4. Display Student"
                                    "\n5. Remove Student"
                                    "\n6. Sign Out and Exit\n";
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
                                    system.displayStudentsTable();
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

                            cout << "\nPress Enter to continue...";
                            cin.ignore(); // Clear the buffer
                            cin.get();    // Wait for the Enter key
                            clearScreen(); // Clear the terminal screen

                        } while (choice != 6 && choice !=7 && choice !=8);

                    } else {
                        cout << "User is already logged in. Please sign-out first." << endl;
                    }
                    break;
                } else {
                    cout << "Authentication failed. Please try again." << endl;

                }
            } while (false);
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

    return 0;
}
