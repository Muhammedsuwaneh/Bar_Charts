#include <iostream>
#include <string>
#include <iomanip>
#include "BarChart.h"
#include "BarChartNode.h"

/// <summary>
/// Initializes the filename 
/// reads data from file 
/// </summary>
/// <param name="filename">name of file to the data read from</param>
BarChart::BarChart(std::string filename) {

	this->data.open(filename, std::ios::in);

	std::getline(data, this->data_title);
	std::getline(data, this->y_title);
	data >> this->data_size >> this->rows;

	this->rows += 5;
	this->cols = this->data_size * 10;

	chart_Matrix = new char* [this->rows];
	for(int i = 0; i < this->rows; i++) 
		chart_Matrix[i] = new char[this->cols];
	setValues();
}

/// <summary>
/// Release allocated memory
/// </summary>
BarChart::~BarChart() {
  
	delete[] chart_Matrix;
}

/// <summary>
/// Set main chart values 
/// </summary>
void BarChart::setValues() {

	this->mean = 0.0;
	
	int count = this->rows - 1;
	int n = count / 5;

	for (int i = 0; i <= n; i++) {
		y_labels.push_back(count);
		count -= 5;
	}
}

/// <summary>
/// Get bar chart mean 
/// </summary>
/// <returns></returns>
double BarChart::getMean() const {
	return this->mean;
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
double BarChart::getTotal() const {
	return this->total;
}

/// <summary>
/// Resets chart 
/// </summary>
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

/// <summary>
/// Read data from file and populate chart 
/// </summary>
void BarChart::readData() {

	reset_Chart();

	int h;
	std::string l;

	BarChartNode* node = NULL;
	int count = 8, increment = 0;
	int i = 0, sum = 0;

	while (i < this->data_size) {

		data >> h >> l;
		node = addNode(node, h, l);
		populateChart(node, &count, &increment);
		increment += count + 2;
		x_labels.push_back(node->label);
		sum += node->height;
		i++;
	}

	computeMean(sum);
}

/// <summary>
/// Setups a node for each bar 
/// </summary>
/// <param name="head"></param>
/// <param name="h"></param>
/// <param name="l"></param>
/// <returns></returns>
BarChartNode* addNode(BarChartNode*head, int h, std::string l) {

	BarChartNode* temp = new BarChartNode();

	temp->height = h;
	temp->label = l;
	temp->next = NULL;

	return temp;
}

/// <summary>
/// Populates chart based on generated node 
/// </summary>
/// <param name="node"></param>
/// <param name="count"></param>
/// <param name="increment"></param>
void BarChart::populateChart(BarChartNode* node, int* count, int* increment) {

	for (int i = this->rows - 2; i > (this->rows-2) - node->height; i--) {

		for (int j = *increment + 1; j < *count + *increment + 1; j++) {

			 this->chart_Matrix[i][j] = '*';
		}
	}
}

/// <summary>
/// Displays chart 
/// </summary>
void BarChart::displayChart() {

	readData();

	int n = this->rows, count = 0;

	std::cout << "\n " << std::right << std::setw(70) << this->data_title << std::endl;

	// display Chart
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
	std::cout << "\n";
	std::cout << std::setw(5) << "  ";
	// display labels
	for (int i = 0; i < this->x_labels.size(); i++)
		std::cout << this->x_labels[i] << "    ";

	std::cout << "\n\n";
	std::cout << std::setw(10) << "   ";
	std::cout << "Total " << this->y_title << " is: " << this->getTotal() << "\n";
	std::cout << std::setw(10) << "   ";
	std::cout << "Average " << this->y_title << " is: " << this->getMean() << "\n";
}

/// <summary>
/// Compute mean 
/// </summary>
/// <param name="sum"></param>
void BarChart::computeMean(int sum) {

	this->total = sum;
	this->mean = this->total / (double)this->data_size;
}