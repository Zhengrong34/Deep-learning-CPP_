
#include "../include/Matrix.h"


#include <random>
#include <vector>
#include <iostream>

using namespace std;

Matrix::Matrix(int numRows, int numCols, bool isRandom)
{
	this ->numRows = numRows;
	this ->numCols = numCols;

	// loop row then col wise
	for (int i = 0; i < numRows; i++) {
		// vector of number for columns [1,2,3,4,5]
		vector<double> colValues;
		for (int j = 0; j < numCols; j++) {
			
			double r = 0.00;
			if (isRandom) {
				r = this->generateRandomValues();
			}
			colValues.push_back(r);
		}

		this->values.push_back(colValues);
	}
}


void Matrix::printToConsole() {
	for (int i = 0; i < numRows; i++) {
		vector<double> vec;
		//vec = this->values.at(i);
		//  ==========================================
		// converts vector doubles to a string for printing
		// iterator is vector of double.. not int. same effect as below
		//std::ostringstream vts;
		//if (!vec.empty())
		//{
			// Convert all but the last element to avoid a trailing "," 
		//	std::copy(vec.begin(), vec.end() - 1,
		//		std::ostream_iterator<double>(vts, "\t\t "));

			// Now add the last element with no delimiter 
		//	vts << vec.back();
		//}
		//cout << vts.str() << endl;
		// end print columns

		for (int j = 0; j < numCols; j++) {
			cout << this->values.at(i).at(j) << "\t" ;
		}
		cout << endl;
	}
}




void Matrix::setValue(vector< vector<double> > new_vector) {
	this->values = new_vector;
}

double Matrix::generateRandomValues(){
	std::random_device rd;
	std::mt19937 gen(rd());
	std:uniform_real_distribution<>dis(0, 1);
	return dis(gen);
}



Matrix *Matrix::transpose() {

	vector< vector<double> > transposed;
	for (int i1 = 0; i1 < this->numCols; i1++) {
		// vector of number for columns [1,2,3,4,5]
		//init vector -- use cout to debug -- prev j1 < was missing so forever going through rows
		vector<double> colValues;
		for (int j1 = 0; j1 < this->numRows; j1++) {
			double r = 0.00;
			colValues.push_back(r);
		}
		transposed.push_back(colValues);
	}


	for (int i = 0; i < this->numRows; i++) {
		for (int j = 0; j < this->numCols; j++) {
			// becareful of assignment this->values = transpose u are not assigning val to transpose!!
			 transposed.at(j).at(i) = this->values.at(i).at(j);
		}
	}

	Matrix *m2 = new Matrix(this->numCols, this->numRows, false);

	m2->setValue(transposed);
	//this->setValue(transposed);
	//swapping
	//int temp;
	//temp = this->numCols;
	//this->numCols = this->numRows;
	//this->numRows = temp;

	return(m2);
}


void Matrix::setIndValues(int row, int col, double val) {
	this->values.at(row).at(col) = val;
}