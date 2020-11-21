#include <iostream>
#include <string>
#include <iomanip>
#include "BarChart.h"
#include "BarChartNode.h"

BarChart::BarChart() {

	this->head = NULL;
	chart_Matrix = new char* [this->rows];
	y_labels = new int[this->rows/5];
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
	
	int count = this->rows - 1;
	int n = count / 5;

	for (int i = 0; i <= n; i++) {
		y_labels[i] = count;
		count -= 5;
	}
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

void BarChart::readData() {

	this->data.open("dataSet1.txt", std::ios::in);

	std::getline(data, this->data_title);
}

void BarChart::displayChart() {

	reset_Chart();
	readData();

	int n = this->rows, count = 0;

	std::cout << "\n " << std::right << std::setw(70) << this->data_title << std::endl;

	for (int i = 0; i < this->rows; i++) {

		if (n == this->y_labels[count]) {

			std::cout << std::setw(5) << y_labels[count];
			count++;
		}
		else std::cout << std::setw(5) << " ";

		for (int j = 0; j < this->cols; j++) {

			std::cout << this->chart_Matrix[i][j];
		}

		std::cout << "\n";
		n--;
	}
}