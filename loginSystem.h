//
// Created by muala on 5/13/2022.
//
#include <string>
#ifndef LOGINGIT_LOGINSYSTEM_H
#define LOGINGIT_LOGINSYSTEM_H
#include <string>

using namespace std;
//function prototypes

//registration
void addInfo(string, string);

bool checkEmail(string);

bool checkName(string);

bool isValidEmail(string);

bool isValidName(string);

bool isValidNum(string);

string encrypt(string password);

string decrypt(string password);

string enterPassword();

string enterPassword2();

bool matchPassword();

bool isValid();

void displayRules();

void registerNew();

//login
void login();

void changePass();

struct user {
    string name;
    string email;
    string password;
    string number;
};

#endif //LOGINGIT_LOGINSYSTEM_H
