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
	void ControlFirstMenu(int _choice);
	void ControlSecondMenu(int x1);
	void MenuInit();

	virtual ~Menu();

private:

	bool _loginOK;
	bool _end;
	int _choice;

};

#endif
