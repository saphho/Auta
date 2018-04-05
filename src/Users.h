/*
 * Users.h
 *
 *  Created on: 7. 1. 2018
 *      Author: marty
 */

#ifndef USERS_H_
#define USERS_H_

#include <cstring>
#include <iostream>

using namespace std;

class Users {
public:
	Users();
	bool Login();
	bool Logout();
	void CreateUser();
	bool ExitProgram();
	void SaveToFile (Users unit[], int size, const char* fileName);
	void SaveToFile (string username, char * password, const char* fileName);
	void GetErrorMessage (bool succesLogin, bool disableAccount, bool lockedAccount);

	void ComparePassword (char * password1, char * password2, int lenghtPassword);
	void EnterThePassword();

	virtual ~Users();




private:

	string username;
	string password;

	string accountStatus1 = "enable";
	string accountStatus0 = "disable";

	string tempUser;
	string tempPassword;

	string accountStatus;

	short wrongPassword;
	short countLogin;

	bool not_matchPassword = true;
	bool succesLogin = false;
	bool userOk = false;
	bool accountPass = false;
	bool disableAccount = false;
	bool lockedAccount = false;

	const char* users_FileName = "users.txt";

	const int countUsers = 3;

	char* Password = new char [20];
	int sizePassword = 0;








};

#endif /* Users_H_ */
