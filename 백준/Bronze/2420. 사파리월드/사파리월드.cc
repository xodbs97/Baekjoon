#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
	long long N, M;

	std::cin >> N >> M;

	std::cout << (N - M >= 0 ? N - M : -1 * (N - M));

	return 0;
}