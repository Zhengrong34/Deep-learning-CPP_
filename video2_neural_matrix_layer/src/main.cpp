// CMakeProject1.cpp : Defines the entry point for the application.

#include "../include/CMakeProject1.h"
#include "../include/Matrix.h"
#include "../include/neuron.h"
#include "../include/Layer.h"
#include "../include/NeuralNet.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{


	vector<int> topology;
	topology.push_back(3);
	topology.push_back(2);
	topology.push_back(3);

	NeuralNetwork *nn = new NeuralNetwork(topology);
	
	vector<double> input;
	input.push_back(1.0);
	input.push_back(0.0);
	input.push_back(1.0);
	nn->setCurrentInput(input);
	

	nn->printToConsole();

	int s;
	cin >> s;
	return 0;
}
