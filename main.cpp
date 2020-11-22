/*
*
*@author - Muhammed Suwaneh
*@ESOGU Department of Computer Engineering
*
*
*/

#include <iostream>
#include <iomanip>
#include "BarChart.h";
#include "BarChartNode.h";

void frame() {

	std::cout << "\n";

	std::cout << std::setw(5) << " ";
	for (int i = 0; i < 100; i++)
		std::cout << "=";

	std::cout << "\n";
}
void Test1();
void Test2();

int main() {


	frame();
	Test1();
	frame();
	Test2();
	frame();
	std::cout << "\n\n";
	return 0;
}

void Test1() {

	try {

		std::string filename = "dataSet1.txt";
		BarChart* chart = new BarChart(filename);
		chart->displayChart();

	}
	catch (std::exception const& ex) {

		std::cerr << std::setw(50) << ex.what() << std::endl;
	}
}

void Test2() {

	try {

		std::string filename = "dataSet2.txt";
		BarChart* chart = new BarChart(filename);
		chart->displayChart();

	}
	catch (std::exception const& ex) {

		std::cerr << std::setw(50) << ex.what() << std::endl;
	}
}
