#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int A = 1, B = 1;

	std::cin >> A >> B;
	while (A || B) {
		std::cout << A + B << "\n";

		std::cin >> A >> B;
	}

	return 0;
}