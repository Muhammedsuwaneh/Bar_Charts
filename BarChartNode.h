#ifndef _BARCHARTNODE_
#define _BARCHARTNODE_
#include <string>

/// <summary>
/// Bar chart node 
/// Includes the height of a bar, 
/// label and the next node to point to
/// </summary>
struct BarChartNode {

	int height; // height of bar
	std::string label; // label of each bar
	BarChartNode* next; // next bar node
};

BarChartNode* addNode(BarChartNode*, int, std::string);

#endif
