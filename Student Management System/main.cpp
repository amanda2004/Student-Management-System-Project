#include <iostream>
#include "StudentManagementSystem.h"

using namespace std;

int main()
{
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
                    int phone_number
                    cout << "Enter Student Name: ";
                    cin.ignore(); // Clear the buffer
                    getline(cin, name);
                    cout << "Enter Student ID: ";
                    cin >> student_id;
                    cout << "Enter Study Program: ";
                    cin >> study_program;
                    cout << "Enter Student Cohort: ";
                    cin >> cohort;
                    cout << "Enter Student GPA: ";
                    cin >> gpa;
                    cout << "Enter Student Date Of Birth: ";
                    cin >> date_of_birth;
                    cout << "Enter Student Phone Number: ";
                    cin >> phone_number;
                    system.addStudent(name, student_id, study_program, cohort, gpa, date_of_birth, phone_number);
                }
                break;
            case 2:
                {

                }
                break;
            case 3:
                {

                }
                break;
            case 4:
                {

                }
                break;
            case 5:
                {
                    int id;
                    cout << "Enter the Student ID of the student you want to remove: ";
                    cin >> id;
                    system.removeStudent(id);
                }
                break;
            case 6:
                {

                }
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 6);

    return 0;
}
