#include "Menu.h"
#include "Users.h"
#include "Cars.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>


Users user;
Cars car;


Menu::Menu() {

	_end = false;
	_loginOK = false;
	_choice = 0;
}

Menu::~Menu() {

}

void Menu::ShowFirstMenu()
{
	cout << "\n**********************";
	cout << "\n1. Login";
	cout << "\n2. Create new account";
	cout << "\n3. Exit";
	cout << "\n**********************\n";
}

void Menu::ShowSecondMenu()
{
	cout << "\n**********************";
	cout << "\n1. Insert new car";
	cout << "\n2. Find car";
	cout << "\n3. Logout";
	cout << "\n**********************\n";
}

void Menu::ControlFirstMenu (int x)
{
	switch (x)
	{
		case 1: _loginOK = user.Login();
				break;

		case 2: user.CreateUser();
				break;

		case 3: _end = user.ExitProgram();
				break;
	}
}

void Menu::ControlSecondMenu (int x1)
{
	switch (x1)
	{
	   case 1: car.Insert();
		   	   break;

	   case 2: car.LoadCar();
		   	   break;

	   case 3: _loginOK = user.Logout();
			   break;
	}
}


void Menu::MenuInit()
{

	while (_end == false)
	{
		ShowFirstMenu();
		cin >> _choice;
		cin.get();
		ControlFirstMenu(_choice);

		while  (_loginOK == true and _end == false)
		{
			ShowSecondMenu();
			cin >> _choice;
			cin.get();
			ControlSecondMenu(_choice);
		}
	}
}










