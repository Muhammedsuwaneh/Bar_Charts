#include <iostream>
#include "BarChart.h"
#include "BarChartNode.h"

BarChart::BarChart() {

	this->head = NULL;
	chart_Matrix = new char* [this->rows];
	for(int i = 0; i < this->rows; i++) 
		chart_Matrix[i] = new char[this->cols];
	setValues();
}

BarChart::~BarChart() {
   
	delete[] chart_Matrix;
}

void BarChart::setValues() {

	this->mode = 0.0;
	this->median = 0.0;
	this->mean = 0.0;
}

double BarChart::getMean() const {
	return this->mean;
}
double BarChart::getMedian() const {
	return this->median;
}
double BarChart::getMode() const {
	return this->mode;
}

void BarChart::reset_Chart() {

	for (int i = 0; i < this->rows; i++) {

		for (int j = 0; j < this->cols; j++) {

			if (i == 0 || i == this->rows - 1)
				this->chart_Matrix[i][j] = '-';
			else if (j == 0 || j == this->cols - 1)
				this->chart_Matrix[i][j] = '|';
			else
				this->chart_Matrix[i][j] = ' ';
		}
	}
}

void BarChart::displayChart() const {

	for (int i = 0; i < this->rows; i++) {

		for (int j = 0; j < this->cols; j++) {

			std::cout << this->chart_Matrix[i][j];
		}

		std::cout << "\n";
	}
}