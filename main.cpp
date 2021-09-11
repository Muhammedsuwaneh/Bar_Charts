#include <iostream>
#include <iomanip>
#include "BarChart.h";
#include "BarChartNode.h";
#include <windows.h>

/// <summary>
/// This function seperates the various test charts 
/// </summary>
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

	/// Set console size to handle expanding charts 
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);

	MoveWindow(console, ConsoleRect.top, ConsoleRect.left, 1280, 900, true);

	//frame();
	//Test1();
	frame();
	Test2();
	frame();
	std::cout << "\n\n";
	return 0;
}

/// <summary>
/// Test 1 -> Read and display data set 1
/// </summary>
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

/// <summary>
/// Test 2 - Read and display data set 2 
/// </summary>
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
