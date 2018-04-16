#include "Cars.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>

using namespace std;

const char* filename = "document.txt";

int GetNumberOfCars();

Cars::Cars()
{
	_performance = 0;
	_weight = 0;
	_coefficent = 0;
	_year = 0;
}

Cars::~Cars()
{

}

void Cars::Insert()
{
	int i = 0;
	int size = 100;
	char choice = 'y';
	Cars * arrayObject = new Cars[size];

	while (choice !='n')
	{
		arrayObject[i].Set();
		arrayObject[i].SaveToFile();
		cout << "\nAre you wanna save another car ? [Y/N]\n";
		cin >> choice;
		choice = tolower(choice);
		cin.get();
		i++;
	}

	delete [] arrayObject;
}


void Cars::Set()
{
	cout << "\nProducer: ";
	getline(cin,_producer);
	cout <<"Model: ";
	getline(cin,_model);
	cout <<"Year: ";
	cin >> _year;
	cout << "Performance: ";
	cin >> _performance;
	cout << "Weight: ";
	cin >> _weight;
	cin.get();
}

void Cars::FindCar(Cars unit[], int numberOfCars)
{
	string temp_producer;

	cout << "Enter the name of producer: \n";
	getline(cin,temp_producer);

	for (int i = 0; i < numberOfCars;i++)
	{
		if (temp_producer == unit[i]._producer)
			Print(unit,i);
	}
}

void Cars::LoadCar()
{
	int i = 0;
	_numberOfCars = 0;

	_numberOfCars = GetNumberOfCars();
	Cars * unit = new Cars [_numberOfCars];

	ifstream loading(filename, ios_base::in);
	if (!loading.is_open())
		cout<<"Unable to open file \n";

	else
	{
		for ( i = 0; i < _numberOfCars; i++)
		loading >> unit[i]._producer >> unit[i]._model >> unit[i]._year >> unit[i]._performance >> unit[i]._weight >> unit[i]._coefficent;
	}

	FindCar(unit, _numberOfCars);

	loading.close();

	delete [] unit;
}

void Cars::SaveToFile()
{
	ofstream saving(filename, std::ofstream::out | std::ofstream::app);
	saving.setf(ios_base::fixed, ios_base::floatfield);
	saving.precision(4);

	if (!saving.is_open())
	{
		cout << "Unable to load file \n";
		exit(EXIT_FAILURE);
	}
	else
		saving << "\n" << _producer << " " << _model << " " << _year << " " << _performance << " " << _weight << " " << Coefficent(_performance,_weight);

	saving.close();
}


void Cars::Print(Cars unit[],int counter)
{
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.precision(4);

	cout << "\nProducer: " << unit[counter]._producer;
	cout << "\nModel: " << unit[counter]._model;
	cout << "\nYear: " << unit[counter]._year;
	cout << "\nPerformance: " << unit[counter]._performance << " Kw";
	cout << "\nWeight: " << unit[counter]._weight << " Kg";
	cout << "\nCoefficent: " << unit[counter]._coefficent << "\n";
}


double Cars::Coefficent(double _performance, double _weight)
{
	return _coefficent = _performance/_weight;;
}



int GetNumberOfCars()
{
	int numberOfCars = 0;
	int size = 0;
	string element;

	ifstream loading(filename, ios_base::in);
	if (!loading.is_open())
		cout<<"Unable to open file \n";
	else
	{
		while (loading >> element)
			size++;

	numberOfCars = size / 6;
	}

	return numberOfCars;
}






























