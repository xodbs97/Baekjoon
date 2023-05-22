#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>

int main()
{
	double A, B;

	std::cout.precision(10);
	std::cin >> A >> B;
	std::cout << A / B;

	return 0;
}