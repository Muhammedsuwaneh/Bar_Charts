#ifndef _BARCHART_
#define _BARCHART_
#include <string>
#include <fstream>
#include <vector>
#include "BarChartNode.h"

class BarChart
{
private:
	double mode, mean, median;
	int rows, cols, data_size;
	char** chart_Matrix;
	std::vector<std::string> x_labels;
	std::vector<int>y_labels;
	std::fstream data;
	std::string data_title;
public:
	BarChart(std::string);
	~BarChart();
	void setValues();
	double getMean() const;
	double getMedian() const;
	double getMode() const;
	void reset_Chart(); 
	void readData();
	void populateChart(BarChartNode*, int*, int*);
	void displayChart();
	// calculate mean
    // calculate median
    // calculate mode
    // compute highest width
	// display results
};

#endif