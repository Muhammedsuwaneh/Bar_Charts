#ifndef _BARCHART_
#define _BARCHART_
#include <vector>
#include "BarChartNode.h"

class BarChart
{
private:
	BarChartNode* head;
	double mode, mean, median;
	char** chart_Matrix;
	const int rows = 31;
	const int cols = 100;
public:
	BarChart();
	~BarChart();
	void setValues();
	double getMean() const;
	double getMedian() const;
	double getMode() const;
	void reset_Chart(); 
	// next to do
	// get chart width and label from user
	// add label and width to node 
	// create a chart
	void displayChart() const;
	// calculate mean
    // calculate median
    // calculate mode
    // compute highest width
	// display results
};

#endif