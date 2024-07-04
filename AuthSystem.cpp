#include <iostream>
#include <thread>
#include <chrono>
#include "DataValidInput.cpp"

using namespace std;

// Declare a structure called User
struct User
{
    string username,password;
    // Initialize name and password
    User(string username, string password) : username(username), password(password) {}
    
    // Getter and setter
    string getUsername() const {return username;}
    string getPassword() const {return password;}
};

// Declare a class called AuthSystem
class AuthSystem
{
private:
    User user;
public:
    // Constructor for AuthSystem
    AuthSystem() : user("nunt", "nunt") {}
    // Function to authenticate
    bool authenticate() {
        cout << "\n======Authenticating System======\n\n";
        int attempt = 3;
        while (attempt != 0)
        {   
            system("cls");
            string inputUsername = DataValidInput::getStringInput("Enter username\n->");
            string inputPassword = DataValidInput::getStringInput("Enter password\n->");
            cout << "Login..." << endl;
            
            // check if correct
            if (inputUsername == user.getUsername() && inputPassword == user.getPassword()) {
                cout << "Login successful!" << endl;
                
                // grant access
                return true;
            }
            else {
                cout << "Incorrect username or password. Attempts left: " << --attempt << "\n\n";
                // return false;
            }
        }
        // return false when attempts are exhausted
        cout << "Maximum attempts reached. Access denied." << endl;
        
        return false;
    }
};
