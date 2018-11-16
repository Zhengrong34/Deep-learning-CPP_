
#include "../include/NeuralNet.h"
#include "../include/Layer.h"
#include "../include/Matrix.h"


NeuralNetwork::NeuralNetwork(vector<int> topology) {
	this->topologySize = topology.size();
	for(int i = 0; i < topologySize; i++) {
		Layer *l = new Layer(topology.at(i));
		this->layers.push_back(l);
	}
	for (int i = 0; i < (topologySize - 1); i++) {
		Matrix *m = new Matrix(topology.at(i), topology.at(i + 1), true);
		this->weightMatrixes.push_back(m);
	}
}

void NeuralNetwork::setCurrentInput(vector<double> input) {
	this->inputLayer = input;
	for (int i = 0; i < input.size(); i++) {
		this->layers.at(0)->setVal(i, input.at(i));
	}
}

void NeuralNetwork::printToConsole() {
	int n_layers;
	n_layers = this->layers.size();
	cout << n_layers <<" n_layers"<< endl;
	
	for (int i = 0; i < n_layers ; i++) {
		cout << "Layer:  " << i << endl;
		// cannot i = 0, result in infinite loop
		if (i == 0) {
			Matrix *m3 = this->layers.at(i)->matrixifyVal();
			m3->printToConsole();
		} else {
			Matrix *m3 = this->layers.at(i)->matrixifyActivatedVal();
			m3->printToConsole();
		}
	}

	for (int i = 0; i < n_layers-1; i++) {
		cout << "Weight metric between layer :  " << i<< " and "<< i+1 << endl;
		this->weightMatrixes.at(i)->printToConsole();
	}
}