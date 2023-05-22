#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>

int main()
{
	int A, B;

	std::cin >> A >> B;


	std::cout << A + B << std::endl << A - B << std::endl << A * B << std::endl << A / B << std::endl << A % B << std::endl;

	return 0;
}