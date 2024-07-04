#include <iostream>
#include <fstream>
#include <iomanip>
#include "ProductApplication.cpp"
#include "StaffApplication.cpp"
#include "DataValidInput.cpp"
#include "display.cpp"
#include "AuthSystem.cpp"
using namespace std;
class Application {
private:
enum MainMenu {PRODUCT = 1, STAFF = 2, EXIT = 3,
               LOGIN=1, REGIS=2};
public:

void run(){
    AuthSystem authsystem;
    if (authsystem.authenticate()){
    int choice, choicelogin;
    while(true){
        system("cls");
        displayMain();
        choice = DataValidInput::getIntInput("Enter your choice: ");
        switch(choice){
        case PRODUCT:
       
            ProductApplication productApp;
            productApp.run();
            break;
        case STAFF:
    
            StaffApplication staffApp;
            staffApp.run();
            break;
        case EXIT:
     
            cout << "Exit Program"<<endl;
            return;
        default :
            cout<<"!!!Invalid input!!!"<<endl;
            break;
        }
    }
}
}
};
