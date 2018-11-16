#pragma once


#ifndef neuron_H
#define neuron_H

#include<iostream>

using namespace std;

// header declaration -- pch.h ^ if other filethen ifndef other files :D


class Neuron
{
public:

	Neuron(double val);

	// fast sigmoid function
	// f(x) = x / (1 + |x|)
	void activate();

	

	// set value then activate and derive
	// function signature must be the same means the arg must be same too!
	void setVal(double val);

	// f'(x) = f(x) * (1- f(x))
	void derive();

	//Getattr
	double getVal() { return this->val; }
	double getactivatedVal() { return this->activatedVal; }
	double getderivedVal() { return this->derivedVal; }


private:
	double val;
	double activatedVal;
	// derivative
	double derivedVal;
};

// TODO: add headers that you want to pre-compile here

#endif //neuron_H