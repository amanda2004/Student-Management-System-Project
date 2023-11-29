#include "User.h"

User::User(const std::string& username, const std::string& password)
    : username(username), password(password), isLoggedIn(false) {}

User::~User() {}

bool User::authenticate(const std::string& inputUsername, const std::string& inputPassword) {
    return (username == inputUsername) && (password == inputPassword);
}

bool User::login() {
    // You might want to include additional logic for handling login, e.g., checking if the user is already logged in
    if (!isLoggedIn) {
        isLoggedIn = true;
        return true;
    } else {
        return false; // User is already logged in
    }
}

void User::logout() {
    isLoggedIn = false;
}

std::string User::getUsername() const {
    return username;
}

bool User::isUserLoggedIn() const {
    return isLoggedIn;
}
