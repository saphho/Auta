/*
 * Menu.h
 *
 *  Created on: 7. 1. 2018
 *      Author: marty
 */

#ifndef MENU_H_
#define MENU_H_

#include <cstring>
#include <iostream>


using namespace std;

class Menu {

public:

	Menu();

	void ShowFirstMenu();
	void ShowSecondMenu();

	void ControlFirstMenu(int x);
	void ControlSecondMenu(int x1);

	void LogicSequenceMenu();

	virtual ~Menu();

private:

};

#endif /* MENU_H_ */
