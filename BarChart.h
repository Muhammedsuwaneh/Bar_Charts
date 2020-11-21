#ifndef _BARCHART_
#define _BARCHART_
#include <string>
#include <fstream>
#include "BarChartNode.h"

class BarChart
{
private:
	BarChartNode* head;
	double mode, mean, median;
	char** chart_Matrix;
	int* y_labels;
	const int rows = 31;
	const int cols = 100;
	std::fstream data;
	std::string data_title;
public:
	BarChart();
	~BarChart();
	void setValues();
	double getMean() const;
	double getMedian() const;
	double getMode() const;
	void reset_Chart(); 
	void readData();
	// add label and width to node 
	// create a chart
	void displayChart();
	// calculate mean
    // calculate median
    // calculate mode
    // compute highest width
	// display results
};

#endif