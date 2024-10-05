## Student Management System Project
The Student Management System is a comprehensive software solution designed to automate various school operations such as managing student data, academic records, admissions, and more. This system helps streamline school processes by providing features like student record management, data validation, sorting, and search functionalities.

Primary Features
--
1. User Authentication: Secure sign-in and registration system for users.
2. Student Management: Add, edit, search, display, and remove student records with details such as name, ID, study program, GPA, date of birth, and more.

Additional Features
--
1. Data Validation: Ensures proper input for student records during editing.
2. Search Functionality: Allows users to search for students using their ID.
3. Bubble Sorting: Sorts student records by their ID using the bubble sort algorithm.

How It Works
--
1. Onboarding: Users can sign in or register to access the system. If sign-in fails, they can retry or create a new account.
2. Student Management: After authentication, users can add new students, edit existing records, search for students, view all students, or delete records.
3. Sorting & Searching: Uses binary search tree (BST) and linked list structures for efficient data storage, search, and retrieval, along with bubble sort for student ID sorting.

Algorithms
--
1. Binary Search Tree (BST): Used for adding, removing, and searching students based on their ID.
2. Linked List: Maintains the insertion order of students.
3. Bubble Sort: Sorts student IDs for display purposes.

Student Management Menu
--
1. Add Student
2. Edit Student
3. Search Student
4. Display All Students
5. Remove Student
6. Sign Out & Exit

Technologies Used
--
1. C++ (Core Logic)
2. Standard Template Library (STL) for data structures (BST, Linked List)

## Getting Started
1. Clone the Repository
   ```bash
   git clone https://github.com/amanda2004/Student-Management-System-Project.git cd student-management-systems
2. Open the Project in VS Code: In VS Code, open the folder you just cloned:
   - Go to File > Open Folder and select the student-management-system directory.
3. Set Up Build Task in VS Code: If you don’t already have a build task set up for compiling C++ code, follow these steps:
   - Press Ctrl+Shift+B to open the Build Task setup.
   - If prompted, choose C++ (g++.exe build active file). This will automatically generate a tasks.json file that tells VS Code how to compile your C++ code.
4. Run the program
   - Press F5 or go to Run > Run Without Debugging to compile and run the program.
   - You will see the program’s menu where you can start managing students (e.g., adding, editing, searching).
