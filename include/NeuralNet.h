#pragma once

#ifndef _NEURALNET_HPP
#define _NEURALNET_HPP

#include <iostream>
#include <vector>
#include "Matrix.h"
#include "Layer.h"

using namespace std;

class NeuralNetwork
{
public:
	NeuralNetwork(vector<int> topology);

	void setCurrentInput(vector<double> input);
	void printToConsole();


private:
	// topology is the number of neuron in each layer eg [3,2,3] 
	vector<int> topology;
	int topologySize;
	vector<Layer *> layers;
	vector<Matrix *> weightMatrixes; // size of topology - 1 : 2 connecting
	vector<double> inputLayer;





};

#endif