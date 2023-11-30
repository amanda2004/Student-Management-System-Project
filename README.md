**PROGRAM**

The Student Management System is a comprehensive software designed to automate a school’s diverse operations from classes, exams to school events calendar. This system helps schools to manage the admission process, student data, academic records, and other school-related information effectively.

**PRIMARY FEATURES**

The primary features of the Student Management System include:

_User Authentication_: The system provides an onboard page where users can sign in or register. If the authentication fails, the user is prompted to try again or register a new account.
_Student Management System_: The system allows users to add, edit, search, display, and remove student records. Each student record includes the student’s name, ID, study program, cohort, GPA, date of birth, and phone number.

**ADDITIONAL FEATURES**
The additional features of the Student Management System include:
_Data Validation_: The system validates the data entered by the user. For example, when editing a student’s information, the user must fill in all the fields one by one; otherwise, the record system will be filled blank in the display menu.
_Search Functionality_: The system allows users to search for a student using their ID. If the student is not found, the system notifies the user.
_Bubble Sorting_:  The system can compute and display a sorted list of students based on their student IDs. This feature uses the bubble sort algorithm, which is a simple sorting algorithm. This feature enhances the system’s ability to organize and manage student data effectively. It can be particularly useful when dealing with a large number of students, as it allows for quick and efficient sorting of student records.

**HOW IT WORKS?**
The Student Management System works as follows:
_Onboard Page_: The system prompts the user to sign in, register, or exit. If the user chooses to sign in, they must enter their username and password. If the authentication fails, the user is prompted to try again. If the user chooses to register, they must enter a new username and password.
_Student Management System Menu_: Once the user is authenticated, the system displays the Student Management System Menu. The user can choose to add, edit, search, display, or remove a student, or sign out and exit.
_Add New Student_: If the user chooses to add a new student, they must enter the student’s name, ID, study program, cohort, GPA, date of birth, and phone number. The system then adds the student to the database.
_Edit Student Information_: If the user chooses to edit a student’s information, they must enter the student’s ID. The system then displays the student’s current information and prompts the user to enter the new information.
_Display Student_: If the user chooses to display a student, the system displays all the students in the database.
_Search Student_: If the user chooses to search for a student, they must enter the student’s ID. The system then searches for the student in the database and displays their information if found.
_Delete Student_: If the user chooses to remove a student, they must enter the student’s ID. The system then removes the student from the database.
_Sign Out_: If the user chooses to sign out, the system will exit the program.

**ALGORITHM**
The algorithm that was used:
_Binary Search Tree (BST)_
Addition of Students: The code implements a binary search tree structure to store student records. When adding a new student, the algorithm traverses the tree based on the student ID, comparing and inserting nodes to the left or right accordingly to maintain the ordering.
Removal of Students: For removing a student, the code follows the logic of BST removal:
Identifies the node to delete.
Handles cases based on the number of children:
If the node has no child or one child, it simply removes the node.
If the node has two children, it finds the successor (the minimum value in the right subtree) and replaces the node's data with the successor's data. Then it recursively removes the successor node.
Searching for Students: Searches for a student by ID, traversing the tree either left or right based on comparisons between the target ID and node values.
_Linked List_
Student Management: In addition to the BST, a linked list is used to maintain the insertion order of students.
When adding a student, a node is created and linked to the head of the list.
During the display or sorting process, this linked list helps maintain the order of insertion.
_Bubble Sorting_
Sorting Students by ID: The code implements a bubble sort algorithm to sort students by their IDs.
It compares adjacent student IDs and swaps them if they are in the wrong order, iterating through the list until no more swaps are needed.

**STUDENT MANAGEMENT SYSTEM MENU**
The Student Management System Menu is the main interface of the system. It provides the following options:
_Add Student_: The user can add a new student to the database.
_Edit Student_: Allows the user to edit a student’s information.
_Search Student_: Allows the user to search for a student using their ID.
_Display Student_: The user can view all the students in the database.
_Remove Student_: Allows the user to remove a student from the database.
_Sign Out and Exit_: Allows the user to sign out and exit the system.
