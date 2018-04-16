#include "Users.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <cstdlib>

void ComparePassword (char* password1, char* password2, int lenghtPassword);
void EnterThePassword();
int GetNumberOfUsers();

const char* users_filename = "users.txt";

using namespace std;

Users::Users()
{
	_wrongPassword = 0;
	_countLogin = 0;
}

Users::~Users()
{

}


bool Users::Login()
{
	_disableAccount = false;
	_lockedAccount = false;
	_succesLogin = false;
	string accountStat0 = "disable";
	string accountStat1 = "enable";
	int i = 0;

	_countUsers = GetNumberOfUsers();
	Users unit[_countUsers];

	ifstream LoadUser (users_filename, std::ios_base::in);

	while (_succesLogin == false && (_countLogin <= 5) && _disableAccount == false && _lockedAccount == false)
	{
		_countLogin++;

		cout << "\nEnter your username: ";
		getline(cin,_tmpUsername);

		cout << "Enter password: ";
		getline(cin,_tmpPassword);

		if (!LoadUser.is_open()){
			cout<<"Unable to open file \n";
			exit(EXIT_FAILURE);}

		else
		{
			LoadUser.clear();
			LoadUser.seekg(0, ios::beg);
				i = 0;

				while (LoadUser >> unit[i]._username >> unit[i]._password >> unit[i]._tmpAccountStat && _succesLogin == false)
				{
					if (_tmpUsername == unit[i]._username)
					{
						if (_tmpPassword == unit[i]._password)
						{
							if (unit[i]._tmpAccountStat == accountStat1)
								_succesLogin = true;
								else
								_lockedAccount = true;
						}
						else
						{
						    _wrongPassword++;
							if (_wrongPassword >= 3)
							{
							cout << "\nYou have locked out your account, please contact your administrator" << std::endl;
							unit[i]._tmpAccountStat = accountStat0;
							_disableAccount = true;
							}
						}
					}

					i++;	// counter

				}

				if (_succesLogin == false && _disableAccount == false && _lockedAccount == false)
				cout << "\nBad username or password !\n";
		}

	GetErrorMessage (_succesLogin,_disableAccount,_lockedAccount);

	}

	LoadUser.close();

	SaveToFile(unit,_countUsers,users_filename);

	return _succesLogin;

}

void Users::CreateUser()
{
	string username;
	string tempUsername;
	_sizePassword = 0;
	_not_matchPassword = true;
	_userExist = true;

	bool upperCaseChar = false;
	bool numericalChar = false;
	bool rightPassword = false;
	const int MIN_lenght = 8;
	const int MAX_lenght = 20;
	int ascii_dec;
	char x;


	ifstream LoadUser (users_filename, std::ios_base::in);

	while (_not_matchPassword == true)
	{
		cout << "\n(8_char,1_uppercase,1_number)" << std::endl;


	while (_userExist == true)
	{
		cout << "\nEnter the username: ";
		getline(cin,tempUsername);
		LoadUser.clear();
		LoadUser.seekg(0, ios::beg);
		_userExist = false;

	while (LoadUser >> username)
	{
		if (tempUsername == username)
		{
			cout << "Username is already used !\n";
			_userExist = true;
		}
	}

	}

	EnterThePassword();

	}

	_not_matchPassword = true;

	while (rightPassword == false)
	{
		for (int i = 0; i < _sizePassword;i++)
			{
				x = _Password[i];
				ascii_dec = x;
					if((ascii_dec >= 65 && ascii_dec <=90) && (_sizePassword >= MIN_lenght && _sizePassword <= MAX_lenght))
						upperCaseChar=true;
					if((ascii_dec >= 48 && ascii_dec <=57) && (_sizePassword >= MIN_lenght && _sizePassword <= MAX_lenght))
						numericalChar=true;
			}
	if (numericalChar && upperCaseChar == true)
	{
		rightPassword = true;
	//	std::cout << "\nThis is right password.";
	}

	else
	{

		cout << "\nThis is not complex password.\n";

		while (_not_matchPassword == true)

			EnterThePassword();
	}
	}

	SaveToFile (tempUsername,_Password,users_filename);

	delete [] _Password;

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
				_not_matchPassword = false;
				continue;
			}
			else
				_not_matchPassword = true;
		}
	if (_not_matchPassword == true)
		std::cout << "\nPasswords do not match\n";
}



void Users::SaveToFile (Users unit[], int size, const char* fileName)
{

	ofstream writeStruct (fileName, std::ios_base::out);

	if (!writeStruct.is_open())
	{
		cout << "Unable to open file \n";
		exit(EXIT_FAILURE);
	}
	else
	{
		for (int i = 0; i < _countUsers; i++)
		writeStruct << unit[i]._username << " " << unit[i]._password << " " << unit[i]._tmpAccountStat << "\n";
	}
	writeStruct.close();
}


void Users::SaveToFile(string username, char * password, const char* fileName)
{
	string accountStat1 = "enable";
	ofstream SaveUser (fileName, std::ofstream::out | std::ofstream::app);

	if (!SaveUser.is_open())
	{
		cout << "Unable to open file. \n";
		exit(EXIT_FAILURE);
	}
		else
	{
		SaveUser << username << " " << password << " " << accountStat1 << "\n";
		cout << "\nUser account succesfully created\n";

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
		cout << "\nlogin OK\n";
		cout << "\nHello " << _tmpUsername << "\n";
	}


	try
	{
		if (lockedAccount == true)
			throw 2;

	}catch(int y)
	{
		cout << "\nLocked user account -> IT department\n";

	}

	try
	{
		if (_succesLogin == false && (_countLogin == 5) && _disableAccount == false && _lockedAccount == false)
			throw 3;

	}catch(int z)
	{
		cout << "\nToo many unsuccess login\n";
	}
}



bool Users::Logout()
{
	_succesLogin = false;
	cout << "\nSuccesfully logout\n";
	return _succesLogin;
}

bool Users::ExitProgram()
{
	bool exitProgram = true;
	cout << "\nEnd - Have a nice day\n";
	return exitProgram;
}


void Users::EnterThePassword()
{
	char* Password1 = new char [20];

	cout << "Enter the password: ";
	cin.getline(_Password, 20);

	cout << "Re-type password: ";
	cin.getline(Password1, 20);

	_sizePassword = strlen(_Password);
	ComparePassword(_Password,Password1,_sizePassword);
}

int GetNumberOfUsers()
{
	int size = 0;
	string element;
	int numberOfUsers = 0;

	ifstream counting (users_filename, ios_base::in);

	if (!counting.is_open())
		cout << "Unable to open file. \n";
	else
	{
		while (counting >> element)
			size++;

		numberOfUsers = size / 3;
	}

	return numberOfUsers;

}











