/*
 * Users.cpp
 *
 *  Created on: 7. 1. 2018
 *      Author: marty
 */

#include "Users.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <cstdlib>

void ComparePassword (char* password1, char* password2, int lenghtPassword);
void EnterThePassword();

using namespace std;

Users::Users()
{
	wrongPassword = 0;
	countLogin = 0;
}

Users::~Users() {

}


bool Users::Login()
{
	Users unit[countUsers];

	disableAccount = false;
	lockedAccount = false;

	int i = 0;

	ifstream LoadUser (users_FileName, std::ios_base::in);

	while (succesLogin == false && (countLogin <= 5) && disableAccount == false && lockedAccount == false)
	{
		countLogin++;

		cout << "\nEnter your username: ";
		getline(cin,tempUser);

		cout << "Enter password: ";
		getline(cin,tempPassword);

		if (!LoadUser.is_open()){
			cout<<"Unable to open file \n";
			cout<<"Program will now terminate \n";
			exit(EXIT_FAILURE);}

		else
		{
			LoadUser.clear();
			LoadUser.seekg(0, ios::beg);
				i = 0;

				while (LoadUser >> unit[i].username >> unit[i].password >> unit[i].accountStatus && succesLogin == false)
				{
					if (tempUser == unit[i].username)
					{
						if (tempPassword == unit[i].password)
						{
							if (unit[i].accountStatus == accountStatus1)
								succesLogin = true;
								else
								lockedAccount = true;
						}
						else
						{
						    wrongPassword++;
							if (wrongPassword >= 3)
							{
							cout << "\nYou have locked out your account, please contact your administrator" << std::endl;
							unit[i].accountStatus = accountStatus0;
							disableAccount = true;
							}
						}
					}

					i++;	// counter

				}

				if (succesLogin == false && disableAccount == false && lockedAccount == false)
				cout << "\nBad username or password !" << endl;
		}

	GetErrorMessage (succesLogin,disableAccount,lockedAccount);

	}

	LoadUser.close();

	SaveToFile(unit,countUsers,users_FileName);

	return succesLogin;

}

void Users::CreateUser()
{
	string username;
	string tempUsername;

	char x;

	bool upperCaseChar = false;
	bool numericalChar = false;
	bool rightPassword = false;

	const int MIN_lenght = 8;
	const int MAX_lenght = 20;

	int ascii_decimal;

	ifstream LoadUser (users_FileName, std::ios_base::in);

	while (not_matchPassword == true)
	{
		cout << "\n(8_char,1_uppercase,1_number)" << std::endl;

		LoadUser.open("members.txt");

	while (userOk == false)
	{
		cout << "\nEnter the username: ";
		getline(cin,tempUsername);
		LoadUser.clear();
		LoadUser.seekg(0, ios::beg);
		userOk = true;

	while (LoadUser >> username /*>> password*/)
	{
		if (tempUsername == username)
		{
			cout << "Username is already used !" << std::endl;
			userOk = false;
		}
	}

	}

	EnterThePassword();

	}

	not_matchPassword = true;

	while (rightPassword == false)
	{
		for (int i = 0; i < sizePassword;i++)
			{
				x = Password[i];
				ascii_decimal = x;
					if((ascii_decimal >= 65 && ascii_decimal <=90) && (sizePassword >= MIN_lenght && sizePassword <= MAX_lenght))
						upperCaseChar=true;
					if((ascii_decimal >= 48 && ascii_decimal <=57) && (sizePassword >= MIN_lenght && sizePassword <= MAX_lenght))
						numericalChar=true;
			}
	if (numericalChar && upperCaseChar == true)
	{
		rightPassword = true;
	//	std::cout << "\nThis is right password.";
	}

	else
	{

		cout << "\nThis is not complex password." << std::endl;

		while (not_matchPassword == true)

			EnterThePassword();
	}
	}

	SaveToFile (tempUsername,Password,users_FileName);

}

bool Users::Logout()
{
	succesLogin=false;
	cout << "\nSuccesfully logout" << std::endl;
	return succesLogin;
}

bool Users::ExitProgram()
{
	bool exitProgram = true;
	cout << "\nEnd - Have a nice day" << std::endl;
	return exitProgram;
}


void Users::EnterThePassword()
{
	char* Password1 = new char [20];

	cout << "Enter the password: ";
	cin.getline(Password, 20);

	cout << "Re-type password: ";
	cin.getline(Password1, 20);

	sizePassword = strlen(Password);
	ComparePassword(Password,Password1,sizePassword);
}

/// if password matche

void Users::ComparePassword (char * password1, char * password2, int lenghtPassword)
{

	char a;
	char b;

	for(int i=0; i<lenghtPassword;i++)
		{
			a=password1[i];
			b=password2[i];
			if (a==b)
			{
				not_matchPassword = false;
				continue;
			}
			else
				not_matchPassword = true;
		}
	if (not_matchPassword == true)
		std::cout << "\nPasswords do not match" << std::endl;
}



void Users::SaveToFile (Users unit[], int size, const char* fileName)
{

	ofstream writeStruct (fileName, std::ios_base::out);

	if (!writeStruct.is_open())
	{
		cout << "Unable to open file \n";
		cout << "Program will now terminate \n";
		exit(EXIT_FAILURE);
	}
	else
	{
		for (int i = 0; i < countUsers; i++)
		writeStruct << unit[i].username << " " << unit[i].password << " " << unit[i].accountStatus << std::endl;
	}
	writeStruct.close();
}


void Users::SaveToFile(string username, char * password, const char* fileName)
{

	ofstream SaveUser (fileName, std::ofstream::out | std::ofstream::app);

	if (!SaveUser.is_open())
	{
		cout << "Unable to open file \n";
		cout << "Program will now terminate \n";
		exit(EXIT_FAILURE);
	}
		else
	{
		SaveUser << username << " " << password << " " << accountStatus1 << endl;
		cout << "\nUser account succesfully created" << endl;

		SaveUser.close();
	}
}

void Users::GetErrorMessage (bool succesLogin, bool disableAccount, bool lockedAccount)
{

	try
	{
		if (succesLogin == true && disableAccount == false)
			throw 1;

	}catch(int x)

	{
		cout << "\nlogin OK" << std::endl;
		cout << "\nHello " << tempUser << std::endl;
	}


	try
	{
		if (lockedAccount == true)
			throw 2;

	}catch(int y)
	{
		cout << "\nLocked user account -> IT department" << std::endl;

	}

	try
	{
		if (succesLogin == false && (countLogin == 5) && disableAccount == false && lockedAccount == false)
			throw 3;

	}catch(int z)
	{
		cout << "\nToo many unsuccess login";
		cout << std::endl;\
	}

}









