#ifndef CARS_H_
#define CARS_H_

#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

class Cars {

public:
	Cars();

	void Insert();
	void Set();
	void FindCar(Cars unit[], int numberOfCars);
	void Print(Cars unit[], int counter);
	void LoadCar();
	void SaveToFile();
	double Coefficent(double p, double w);

	virtual ~Cars();

private:

	string _producer;
	string _model;
	int _year;
	int _performance;
	int _weight;
	double _coefficent;
	int _numberOfCars;

};

#endif
