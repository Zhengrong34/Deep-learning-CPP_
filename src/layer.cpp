
#include "../include/Layer.h"

Layer::Layer(int size)
{
	this->size = size;
	for (int i = 0; i < size; i++) {
		Neuron *n = new Neuron(0.00);
		this->neurons.push_back(n);
	}
}

void Layer::setVal(int i, double j) {
	this->neurons.at(i)->setVal(j);
}

Matrix *Layer::matrixifyVal() {
	Matrix *m = new Matrix(1, this->neurons.size(), false);
	for (int i = 0; i < this->neurons.size(); i++) {
		m->setIndValues(0, i, this->neurons.at(i)->getVal());
	}
	return m;
}


Matrix *Layer::matrixifyDerivedVal() {
	Matrix *m = new Matrix(1, this->neurons.size(), false);
	for (int i = 0; i < this->neurons.size(); i++) {
		m->setIndValues(0, i, this->neurons.at(i)->getderivedVal());
	}
	return m;
}

Matrix *Layer::matrixifyActivatedVal() {
	// impt!!
	//
	//must be 0 because matrix has 1 row which is at index 0!!!! impt!!!
	//
	// errro in video is at here set val where set val set at row index and col index!!
	Matrix *m = new Matrix(1, this->neurons.size(), false);
	for (int i = 0; i < this->neurons.size(); i++) {
		// debug based on print statement
		m->setIndValues(0, i, this->neurons.at(i)->getactivatedVal());
	}
	return m;
}
