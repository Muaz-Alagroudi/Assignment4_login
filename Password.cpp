#include <iostream>
#include <string.h>
#include <conio.h>
#include <cctype>
#include <cstring>
#include <sstream>
#include<istream>
#include<fstream>
#include<stdlib.h>

using namespace std;

//8 - Verify that the password is a strong one.If not, display to the user a messageand ask him for
//another password.Search for rules of strong password.

bool isValid(string pass1)
{
	// For checking if password length
	// is between 8 and 15
	if (!((pass1.length() >= 8) &&
		(pass1.length() <= 15)))
		return false;

	// To check space
	if (pass1.find(" ") !=
		std::string::npos)
		return false;

	if (true)
	{
		int count = 0;

		// Check digits from 0 to 9
		for (int i = 0; i <= 9; i++)
		{

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

	if (true)
	{
		int count = 0;
		// Checking capital letters
		for (int i = 65; i <= 90; i++)
		{
			// Type casting
			char c = (char)i;
			string str1(1, c);

			if (pass1.find(str1) !=
				std::string::npos)
				count = 1;
		}
		if (count == 0)
			return false;
	}
	if (true)
	{
		int count = 0;

		// Checking small letters
		for (int i = 97; i <= 122; i++)
		{
			// Type casting
			char c = (char)i;
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


int main()
{
	ios_base::sync_with_stdio(false);
	char pw1[13], pw2[13],ch;
	string pass1,pass2;
	int i = 0;
	int n = i + 1;

	//6 - Display a message of what letters are allowed / required and conditions that must apply to the password.
	cout << "Please Enter Your Password\n";
	cout << "Note that Your Password Must be at least 12 Characteres \n";
	cout << "and must include letters, numbers, special characteres , and upper and lower case.\n";

	//9- Cover the password with ***** while the user is entering it.
	for (int i = 0;i < 12;i++) {
		ch = _getch();
		pass1 += ch;
		pw1[i] = ch;
		ch = '*';
		cout << ch;
		
	}
	cout << endl;

	cout << "Please Repeat your Password:";
	for (int i = 0;i < 12;i++) {
		ch = _getch();
		pass2 += ch;
		pw2[i] = ch;
		ch = '*';
		cout << ch;
	}
	cout << endl;
	
	//7- Repeat the password and make sure it was entered the same twice.
	
	string password1 = pass1;

	if (isValid(password1))
		cout << "Strong Password!" << endl;
	else
	{
		cout << "Weak Password!";
		cout << "Please Enter another password include letters, numbers, special characteres , and upper and lower case." << endl;
	}

	while (pass1 != pass2, i < 1)
	{
		i++;
		n++;
		if (pass1==pass2) {
			/*10-If registration is valid, the user profile, ID and password are added to the list of system users
			and stored in the user file*/
			//ofstream reg("database.txt", ios::app);
			//reg << pw1 << endl;
			//system("cls");
			cout << "Password saved successfuly\n";
		}
		else {
			cout << "Wrong Pasword.\n";
			cout << "The Two Passwords are not the same.\n";
		}
	}
} 