//
// Created by muala on 5/13/2022.
//

#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <conio.h>
#include <regex>
#include "loginSystem.h"

using namespace std;
//************************
//function definitions  ||
//************************

bool checkEmail(string email) {
    string emailInFile;
    fstream emailFile("emails.txt", ios::in);
    while (!emailFile.eof()) {
        emailFile >> emailInFile;
        //cout << emailInFile << endl;
        if (emailInFile == email) {
            return false;
        }
    }
    return true;
}

bool checkName(string name) {
    string nameInFile;
    fstream usernameFile("usernames.txt", ios::in);
    while (!usernameFile.eof()) {
        usernameFile >> nameInFile;
        //cout << emailInFile << endl;
        if (nameInFile == name) {
            return false;
        }
    }
    return true;
}

bool isValidEmail(string email) {
    regex r("[a-zA-Z0-9]+[!#$%&'*+-/=?^`{|]?[@][a-z]+[.][a-z]+");
    if (regex_match(email, r)) {
        return true;
    } else {
        return false;
    }
}

bool isValidName(string name) {
    regex r("[a-zA-Z-]+");
    if (regex_match(name, r)) {
        return true;
    } else {
        return false;
    }
}

bool isValidNum(string num) {
    regex r("[0][1][0-9]{9}");
    if (regex_match(num, r)) {
        return true;
    } else {
        return false;
    }
}

string encrypt(string password) {
    //caesar cipher encryption
    string encrypted = "";
    int len = password.length();
    char encryptedChar;
    for (int i = 0; i < len; i++) {
        encryptedChar = password[i] + 1;
        //cout << encryptedChar << endl;
        encrypted += string(1, encryptedChar);
    }
    return encrypted;
}

string decrypt(string encrypted) {
    //caesar cipher encryption
    string decrypted = "";
    int len = encrypted.length();
    char decryptedChar;
    for (int i = 0; i < len; i++) {
        decryptedChar = encrypted[i] - 1;
        //cout << encryptedChar << endl;
        decrypted += string(1, decryptedChar);
    }
    return decrypted;
}

bool isValid(string pass1) {
    // For checking if password length
    // is between 8 and 15
    if (!((pass1.length() >= 8) &&
          (pass1.length() <= 15)))
        return false;

    // To check space
    if (pass1.find(" ") !=
        std::string::npos)
        return false;

    if (true) {
        int count = 0;

        // Check digits from 0 to 9
        for (int i = 0; i <= 9; i++) {

            // To convert int to string
            string str1 = to_string(i);

            if (pass1.find(str1) !=
                std::string::npos)
                count = 1;
        }
        if (count == 0)
            return false;
    }

    // For special characters
    if (!((pass1.find("@") != std::string::npos) ||
          (pass1.find("#") != std::string::npos) ||
          (pass1.find("!") != std::string::npos) ||
          (pass1.find("~") != std::string::npos) ||
          (pass1.find("$") != std::string::npos) ||
          (pass1.find("%") != std::string::npos) ||
          (pass1.find("^") != std::string::npos) ||
          (pass1.find("&") != std::string::npos) ||
          (pass1.find("*") != std::string::npos) ||
          (pass1.find("(") != std::string::npos) ||
          (pass1.find(")") != std::string::npos) ||
          (pass1.find("-") != std::string::npos) ||
          (pass1.find("+") != std::string::npos) ||
          (pass1.find("/") != std::string::npos) ||
          (pass1.find(":") != std::string::npos) ||
          (pass1.find(".") != std::string::npos) ||
          (pass1.find(",") != std::string::npos) ||
          (pass1.find("<") != std::string::npos) ||
          (pass1.find(">") != std::string::npos) ||
          (pass1.find("?") != std::string::npos) ||
          (pass1.find("|") != std::string::npos)))
        return false;

    if (true) {
        int count = 0;
        // Checking capital letters
        for (int i = 65; i <= 90; i++) {
            // Type casting
            char c = (char) i;
            string str1(1, c);

            if (pass1.find(str1) !=
                std::string::npos)
                count = 1;
        }
        if (count == 0)
            return false;
    }
    if (true) {
        int count = 0;

        // Checking small letters
        for (int i = 97; i <= 122; i++) {
            // Type casting
            char c = (char) i;
            string str1(1, c);

            if (pass1.find(str1) !=
                std::string::npos)
                count = 1;
        }
        if (count == 0)
            return false;
    }
    // If all conditions fails
    return true;
}

void displayRules() {
    //6 - Display a message of what letters are allowed / required and conditions that must apply to the password.
    cout << "\nYour Password Must be at least 12 Characteres \n";
    cout << "and must include letters, numbers, special characteres , and upper and lower case.\n";
}

string enterPassword() {
    int chr;
    string username, password;
    cout << "enter your username\n";
    cin >> username;
    cout << "Enter your password\n";
    cin.clear();
    chr = getch();

    while (chr != 13) {
        password.push_back(chr);
        cout << '*';
        chr = getch();
    }
    return password;
}

string enterPassword2() {
    char chr;
    string passwordStr;

    while (true) {
        chr = getch();
        if (chr == 13) {
            break;
        } else if (chr != '\b') {
            passwordStr.push_back(chr);
            cout << '*';
//            chr = getch();
        }
    }
    return passwordStr;
}

void addInfo(string name, string email) {
    fstream userNameFile("usernames.txt", ios::out | ios::app), emailFile("emails.txt", ios::out | ios::app);
    userNameFile << name << '\n';
    emailFile << email << '\n';
    userNameFile.close();
    emailFile.close();
}

void registerNew() {
    string name, password1, password2, email, number;
    cout << "Registering new user...\n";
    cout << "enter your username :" << " ";
    getline(cin, name);
    while (!checkName(name)) {
        cout << "username already in use, please try again...\n";
        cout << "enter your username :" << " ";
        getline(cin, name);
    }


    cout << "\nenter your email :" << " ";
    getline(cin, email);
    while (!isValidEmail(email)) {
        cout << "\ninvalid email, please try again...\n";
        cout << "enter your email :" << " ";
        getline(cin, email);
    }
    while (!checkEmail(email) && !isValidEmail(email)) {
        cout << "\nemail already registered, please pick a new one...\n";
        cout << "enter your email :" << " ";
        getline(cin, email);
    }
    cout << "\nenter your number :" << " ";
    getline(cin, number);
    while (!isValidNum(number)) {
        cout << "\ninvalid number, please try again...\n";
        cout << "enter your number :" << " ";
        getline(cin, number);
    }
    //password
    displayRules();
    cout << "\nEnter your password :" << " ";
    password1 = enterPassword2();
    while (!isValid(password1)) {
        cout << "\nInvalid password, please try again...\n";
        cout << "enter your password :" << " ";
        password1 = enterPassword2();
    }
    cout << "\nEnter your password again :" << " ";
    password2 = enterPassword2();
    while (password1 != password2) {
        cout << "\nThe passwords do not match, please try again...\n";
        cout << "\nEnter the second password again :" << " ";
        password2 = enterPassword2();
    }
    if (password1 == password2) {
        cout << "\nThe two passwords match !\n";
    }
    addInfo(name, email);
    cout << "\n>>> REGISTRATION SUCCESSFUL ! <<<\n\n";

//    cout << "name :" << name << endl;
//    cout << "email :" << email << endl;
//    cout << "password :" << password1 << endl;
//    cout << "number :" << number << endl;

    fstream infoFile(name + ".txt", ios::out);
    infoFile << name << '\n';
    infoFile << email << '\n';
    infoFile << encrypt(password1) << '\n';
    infoFile << number << '\n';
    infoFile.close();
}

//log in

void login(int code) {
    cout << '\n';
    string username, usernameNewline, password, nameFile, emailFile, passwordFile, numberFile;
    int counter = 0;
    user newUser;

    while (counter < 3) {
        cout << "\nplease enter your log in information" << endl;
        cout << "username : ";
        cin >> username;
        usernameNewline = username + '\n';
        while (!checkName(usernameNewline)) {
            cout << "\nusername does not exist, please try again" << endl;
            cin >> username;
            usernameNewline = username + '\n';
            counter++;
        }
        if (checkName(usernameNewline)) {
            ifstream userFile(username + ".txt");

            userFile >> nameFile;
            userFile >> emailFile;
            userFile >> passwordFile;
            passwordFile = decrypt(passwordFile);
            userFile >> numberFile;
            userFile.close();
        }

        newUser.name = nameFile;
        newUser.email = emailFile;
        newUser.password = encrypt(passwordFile);
        newUser.number = numberFile;

        if (code == 1){
            goto account;
        }
        cout << "password : ";
        password = enterPassword2();
        if (password == passwordFile) {
            break;
        }
        while (password != passwordFile) {
            cout << "\npassword is incorrect, try again..." << endl;
            password = enterPassword2();
            counter++;
        }
        if (password == passwordFile) {
            break;
        }
    }

    if (counter == 3) {
        cout << "\nThree unsuccessful attempts, returning to main menu...\n";
        return;
    } else {
        cout << "\n>>> lOGIN SUCCESSFUL ! <<<\n";

        account :
        cout << "\nYour information : \n";
        cout << "username : " << newUser.name << endl;
        cout << "email    : " << newUser.email << endl;
        cout << "number   : " << newUser.number << endl;

        string choice, oldPass, newPass1, newPass2;
        cout << "\nwould you like to change your password?\n1 - yes\n2 - no\n";
        cin >> choice;
        if (choice == "1") {
            cout << "\nenter your old password : ";
            oldPass = enterPassword2();
            int oldPassCount = 3;
            while (oldPass != decrypt(newUser.password)) {
                cout << "\nthe password is incorrect, try again...\n";
                cout << "tries left: " << oldPassCount << endl;
                oldPassCount--;
                cout << "enter your old password : ";
                oldPass = enterPassword2();
                if (oldPassCount == 0) {
                    cout << "\npassword not changed\n";
                    goto account;
                }
            }
            if (oldPass == decrypt(newUser.password)){
                displayRules();
                cout << "\nEnter your new password : ";
                newPass1 = enterPassword2();
                while (!isValid(newPass1)) {
                    cout << "\nInvalid password, please try again...\n";
                    cout << "enter your password :" << " ";
                    newPass1 = enterPassword2();
                }
                cout << "\nEnter your password again :" << " ";
                newPass2 = enterPassword2();
                while (newPass1 != newPass2) {
                    cout << "\nThe passwords do not match, please try again...\n";
                    cout << "\nEnter the second password again :" << " ";
                    newPass2 = enterPassword2();
                }
                if (newPass1 == newPass2) {
                    cout << "\nThe two passwords match !\n";
                    newUser.password = encrypt(newPass1);
                }
            }
            ofstream newPassFile(newUser.name + ".txt");
            newPassFile << newUser.name << '\n';
            newPassFile << newUser.email << '\n';
            newPassFile << newUser.password << '\n';
            newPassFile << newUser.number << '\n';
            newPassFile.close();
        }
    }
}

bool sendEmail(){
    string command, email, otpEnter, emailToCheck;
    cout << "enter your email : ";
    cin >> email;
    cin.ignore();
    if (!checkEmail(email)){
        cout << "\nWait a few moments..." << endl;
        command = "powershell -command \"$EmailFrom = \"\"\"fcai.cu.eg@gmail.com\"\"\";$EmailTo = \"\"\"" + email + "\"\"\";$Subject = \"\"\"OTP\"\"\";$Body = \"\"\"OTP : " + OTP + "\"\"\";$SMTPServer = \"\"\"smtp.gmail.com\"\"\";$SMTPClient = New-Object Net.Mail.SmtpClient($SmtpServer, 587);$SMTPClient.EnableSsl = $true;$SMTPClient.Credentials = New-Object System.Net.NetworkCredential(\"\"\"fcai.cu.eg@gmail.com\"\"\", \"\"\"tseupwajnritmznu\"\"\");$SMTPClient.Send($EmailFrom, $EmailTo, $Subject, $Body);\"";
        const char *cmd;
        cmd = command.c_str();
        system(cmd);

        otp :
        cout << "\nEnter the OTP : ";
        cin >> otpEnter;
        cin.ignore();
        if (otpEnter == OTP){
            cout << "\n>>> SUCCESS <<<\n";
            return true;
        } else {
            cout << "\nwrong OTP, please try again" << endl;
            goto otp;
        }
    } else {
        cout << "\nThe email you entered is not registered\n";
        return false;
    }
}