
#pragma once

#ifndef Matrix_H
#define Matrix_H

//#include"neuron.h"
//#include"Layer.h"

#include<iostream>
#include<vector>

using namespace std;

class Matrix
{
public:
	Matrix(int numRows, int numCols, bool isRandom);

	Matrix *transpose();

	void printToConsole();

	double generateRandomValues();

	void setValue(vector< vector<double> > new_vector);
	void Matrix::setIndValues(int row, int col, double val);

private:

	int numRows;
	int numCols;

	vector< vector<double> > values;


};


#endif //Layer_H
