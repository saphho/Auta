/*
 * Menu.cpp
 *
 *  Created on: 7. 1. 2018
 *      Author: marty
 */

#include "Menu.h"
#include "Users.h"
#include "Cars.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>


Users user;
Cars car;


bool loginOk = false;
bool endProgram= false;
int choice;


Menu::Menu() {


}

Menu::~Menu() {

}

void Menu::ShowFirstMenu()
{
	cout << "\n**********************" << std::endl;
	cout << "1. Login" << std::endl;
	cout << "2. Create new account" << std::endl;
	cout << "3. Exit" << std::endl;
	cout << "**********************" << std::endl;
}

void Menu::ShowSecondMenu()
{
	cout << "\n**********************" << std::endl;
	cout << "1. Insert new car" << std::endl;
	cout << "2. Find car" << std::endl;
	cout << "3. Edit car" << std::endl;
	cout << "4. Logout" << std::endl;
	cout << "**********************" << std::endl;
}

void Menu::ControlFirstMenu (int x)
{
	switch (x)
	{
		case 1: loginOk = user.Login();
				break;
		case 2: user.CreateUser();
				break;
		case 3: endProgram = user.ExitProgram();
				break;
	}
}

void Menu::ControlSecondMenu (int x1)
{
	switch (x1)
	{
	   case 1: car.InsertCar();
		   	   break;
	   case 2: car.FindCar();
		   	   break;
	   case 4: loginOk=user.Logout();
			   break;

	}
}


void Menu::LogicSequenceMenu()
{
	while (endProgram == false)
	{
	ShowFirstMenu();
	cin >> choice;
	cin.get();
	ControlFirstMenu(choice);

	while  (loginOk == true && endProgram == false)
	{
	ShowSecondMenu();
	cin >> choice;
	cin.get();
	ControlSecondMenu(choice);
	}

	}
}










