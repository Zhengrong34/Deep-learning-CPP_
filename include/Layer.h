#pragma once

#ifndef Layer_H
#define Layer_H

#include"neuron.h"
#include<iostream>
#include<vector>
#include "Matrix.h"



using namespace std;

class Layer
{
public:
	Layer(int size);
	void setVal(int i , double j );
	Matrix *matrixifyVal();
	Matrix *matrixifyDerivedVal();
	Matrix *matrixifyActivatedVal();
private:
	int size;
	vector<Neuron *> neurons;



};


#endif //Layer_H
