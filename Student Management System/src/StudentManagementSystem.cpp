#include "StudentManagementSystem.h"
#include <iostream>

//Constructor
StudentManagementSystem::StudentManagementSystem(): root(nullptr), head(nullptr) {}

//Destructor to free memory
StudentManagementSystem::~StudentManagementSystem()
{
    clearTree(root);
    clearList();
}

// Constructor to initialize user properties
StudentManagementSystem::StudentManagementSystem(const std::string& uname, const std::string& pwd, const std::string& secQuestion, const std::string& secAnswer)
    : username(uname), password(pwd), securityQuestion(secQuestion), securityAnswer(secAnswer), left(nullptr), right(nullptr) {}

// Constructor to initialize the user management system
StudentManagementSystem::StudentManagementSystem() : root(nullptr), logged_in_user(nullptr) {}

// Recursive function to insert a user into the binary search tree
User* StudentManagementSystem::insertUser(User* root, const std::string& username, const std::string& password,
                                       const std::string& secQuestion, const std::string& secAnswer) {
    if (root == nullptr) {
        return new User(username, password, secQuestion, secAnswer);
    }

    if (username < root->username) {
        root->left = insertUser(root->left, username, password, secQuestion, secAnswer);
    } else if (username > root->username) {
        root->right = insertUser(root->right, username, password, secQuestion, secAnswer);
    }

    return root;
}
// Recursive function to authenticate a user in the binary search tree
User* StudentManagementSystem::authenticateUser(User* root, const std::string& username, const std::string& password) {
    if (root == nullptr || (username == root->username && password == root->password)) {
        return root;
    }

    if (username < root->username) {
        return authenticateUser(root->left, username, password);
    } else {
        return authenticateUser(root->right, username, password);
    }
}
// Method to register a new user
void StudentManagementSystem::registerUser() {
    std::string username, password, securityQuestion, securityAnswer;

    std::cout << "Enter username: ";
    std::cin >> username;

    std::cout << "Enter password: ";
    std::cin >> password;

    std::cout << "Enter security question: ";
    std::cin.ignore(); // Clear the newline character from the input buffer
    std::getline(std::cin, securityQuestion);

    std::cout << "Enter security answer: ";
    std::cin >> securityAnswer;

    root = insertUser(root, username, password, securityQuestion, securityAnswer);
}

// Method to sign in a user
void StudentManagementSystem::signIn(const std::string& username, const std::string& password) {
    logged_in_user = authenticateUser(root, username, password);
}
// Method to reset a user's password
void StudentManagementSystem::resetPassword(const std::string& username, const std::string& securityAnswer, const std::string& newPassword) {
    // Find the user by username and verify the security answer
    User* userToReset = authenticateUser(root, username, securityAnswer);

    // If the user and security answer are valid, update the password
    if (userToReset != nullptr) {
        userToReset->password = newPassword;
        std::cout << "Password reset successfully for user: " << username << std::endl;
    } else {
        std::cout << "Invalid username or security answer. Password reset failed." << std::endl;
    }
}
// Method to log out the current user
void StudentManagementSystem::logOut() {
    logged_in_user = nullptr;
}
// Method to get the currently logged-in user
User* StudentManagementSystem::getLoggedInUser() const {
    return logged_in_user;
}

