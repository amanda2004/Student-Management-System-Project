#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User {
private:
    string username;
    string password;
    bool isLoggedIn;

public:
    User(const string& username, const string& password);
    ~User();

    bool authenticate(const string& inputUsername, const string& inputPassword);
    bool login();
    void logout();
    string getUsername() const;
    bool isUserLoggedIn() const;
};

#endif // USER_H
