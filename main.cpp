#include "loginSystem.h"
#include <iostream>

using namespace std;

int main() {
    string userChoice;
    while (true) {
        cout << "\nWELCOME TO THE LOGIN SYSTEM\n"
             << "would you like to\n1 - Register\n2 - Login\n3 - Forgot Password?\n4 - Exit" << endl;
        cin >> userChoice;
        cin.ignore();
        if (userChoice == "1") {
            registerNew();
        } else if (userChoice == "2") {
            login();
        } else if (userChoice == "3") {
          if (sendEmail()){
              login(1);
          }
        } else if (userChoice == "4"){
            return 0;
        } else {
            cout << "invalid choice" << endl;
        }
    }
}

