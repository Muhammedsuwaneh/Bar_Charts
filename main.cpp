#include <iostream>
#include <iomanip>
#include "BarChart.h";
#include "BarChartNode.h";

void frame() {

	for (int i = 0; i < 100; i++)
		std::cout << "=";
}
void Test1();

int main() {

	frame();
	Test1();
	frame();
	
	std::cout << "\n\n";
	return 0;
}

void Test1() {

	std::cout << "\n" << std::setw(40) << "Chart 1" << std::endl;
	try {

		BarChart* chart = new BarChart();
		chart->reset_Chart();
		chart->displayChart();

	}
	catch (std::exception const& ex) {

		std::cerr << ex.what() << std::endl;
	}
}