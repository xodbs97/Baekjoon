#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
	int score;

	std::cin >> score;

	std::cout << (score >= 90 ? "A" : (score >= 80 ? "B" : (score >= 70 ? "C" : (score >= 60 ? "D" : "F"))));

	return 0;
}