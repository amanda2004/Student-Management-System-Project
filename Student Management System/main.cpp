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
