#ifndef _BARCHART_
#define _BARCHART_
#include <string>
#include <fstream>
#include <vector>
#include "BarChartNode.h"

/// <summary>
/// Bar chart class 
/// </summary>
class BarChart
{
private:
	double mean, total;
	int rows, cols, data_size;
	char** chart_Matrix;
	std::vector<std::string> x_labels;
	std::vector<int>y_labels;
	std::fstream data;
	std::string data_title, y_title;
public:
	BarChart(std::string);
	~BarChart();
	void setValues();
	double getMean() const;
	double getTotal() const;
	void reset_Chart(); 
	void readData();
	void computeMean(int);
	void populateChart(BarChartNode*, int*, int*);
	void displayChart();
};

#endif