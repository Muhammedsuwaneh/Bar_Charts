#include <iostream>
#include <iomanip>
#include "BarChart.h";
#include "BarChartNode.h";

void frame() {

	std::cout << std::setw(5) << " ";
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

	try {

		BarChart* chart = new BarChart();
		chart->displayChart();

	}
	catch (std::exception const& ex) {

		std::cerr << ex.what() << std::endl;
	}
}