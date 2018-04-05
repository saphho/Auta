/*
 * Cars.cpp
 *
 *  Created on: 5. 1. 2018
 *      Author: marty
 */

#include "Cars.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <cstdlib>


const int _ActuallSize = 4;
Cars unitCar [_ActuallSize];

int counter = 0;    // counter

using namespace std;

Cars::Cars()
{
	performance = 0;
	weight = 0;
	Var_coefficent = 0;
	year = 0;
}

Cars::~Cars() {

}

void Cars::PrintCar(Cars unit[],int counter)
{
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.precision(4);

	cout << "Producer: " << unit[counter].producer << endl;
	cout << "Model: " << unit[counter].model << endl;
	cout << "Year: " << unit[counter].year << endl;
	cout << "Performance: " << unit[counter].performance << " Kw" << endl;
	cout << "Weight: " << unit[counter].weight << " Kg" << endl;
	cout << "Coefficent: " << unit[counter].Var_coefficent << endl;
	cout << endl;
}

void Cars::SetCar()
{
	cout << "\nProducer: ";
	getline(cin,producer);
	cout <<"Model: ";
	getline(cin,model);
	cout <<"Year: ";
	cin >> year;
	cout << "Performance: ";
	cin >> performance;
	cout << "Weight: ";
	cin >> weight;
	cin.get();
}

double Cars::Coefficent(double p, double w)
{
	Var_coefficent= p/w;
	return Var_coefficent;
}

void Cars::SaveCar(){

	ofstream saveFile;
	saveFile.open("document.txt", std::ofstream::out | std::ofstream::app);

	saveFile.setf(ios_base::fixed, ios_base::floatfield);
	saveFile.precision(4);

	if (!saveFile.is_open()){
		cout<<"Unable to load file \n";
		cout<<"Program will now terminate \n";
			exit(EXIT_FAILURE);}
	else

	saveFile << producer << " " << model << " " << year << " " << performance << " " << weight << " " << Coefficent(performance,weight);

	saveFile.close();
}

void Cars::FindCar()
{
	string tempProducer;

	LoadCar();

	cout << "Enter the name of producer: " << endl;
	getline(cin,tempProducer);

	for (counter = 0; counter < _ActuallSize;counter++)
	{
		if (tempProducer == unitCar[counter].producer)
			PrintCar(unitCar,counter);
	}
}

void Cars::InsertCar()
{
	int size;

	cout << "\nNumber of cars: ";
	cin >> size;
	cin.get();

	Cars arrayObject[size];

	for(int i=0;i < size;i++)
	{
		arrayObject[i].SetCar();
		arrayObject[i].SaveCar();
	}
}

void Cars::LoadCar()
{
	ifstream _loadStruct;
	_loadStruct.open("document.txt", ios_base::in);

	if (!_loadStruct.is_open()){

		std::cout<<"Unable to open file \n";
		std::cout<<"Program will now terminate \n";
		exit(EXIT_FAILURE);}

	else
	{
		for (int i = 0; i < _ActuallSize; i++)
		_loadStruct >> unitCar[i].producer >> unitCar[i].model >> unitCar[i].year >> unitCar[i].performance >> unitCar[i].weight >> unitCar[i].Var_coefficent;
	}

	_loadStruct.close();
}






