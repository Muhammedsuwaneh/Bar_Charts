#include <iostream>

void Test1();

int main() {

	std::cout << "\n\n==========================================================" << "\n\n";
	Test1();
	std::cout << "\n\n==========================================================" << "\n\n";
	
	return 0;
}

void test1() {

	std::cout << "************* Test 1 *************" << std::endl;
	try {








	}
	catch (std::exception const& ex) {

		std::cerr << ex.what() << std::endl;
	}
}