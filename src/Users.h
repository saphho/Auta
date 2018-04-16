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

	string _username;
	string _password;
	string _tmpUsername;
	string _tmpPassword;
	string _tmpAccountStat;

	short _wrongPassword;
	int _sizePassword;
	short _countLogin;
	int _countUsers;

	bool _not_matchPassword;
	bool _succesLogin;
	bool _userExist;
	bool _disableAccount;
	bool _lockedAccount;
	char* _Password = new char [20];

};

#endif
