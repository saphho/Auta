/*
 * Cars.h
 *
 *  Created on: 5. 1. 2018
 *      Author: marty
 */

#ifndef CARS_H_
#define CARS_H_

#include <cstring>
#include <iostream>

using namespace std;

class Cars {

public:

	Cars();
	virtual ~Cars();
	void SetCar();
	void PrintCar(Cars unit[], int counter);
	void SaveCar();
	void LoadCar();
	void EditCar();
	void FindCar();
	void InsertCar();
	double Coefficent(double p, double w);

private:

	string producer;
	string model;
	int year;
	int performance;
	int weight;
	double Var_coefficent;

};

#endif /* Cars_H_ */
