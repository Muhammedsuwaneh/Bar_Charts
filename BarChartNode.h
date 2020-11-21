#ifndef _BARCHARTNODE_
#define _BARCHARTNODE_
#include <string>

struct BarChartNode {

	int height; // height of bar
	std::string label; // label of each bar
	BarChartNode* next; // next bar node
};

BarChartNode* addNode(BarChartNode*, int, std::string);

#endif
