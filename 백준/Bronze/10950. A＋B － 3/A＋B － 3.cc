#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int T;
	std::cin >> T;

	int A, B;

	for (int i = 0; i < T; i++) {
		std::cin >> A >> B;

		std::cout << A + B << "\n";
	}

	return 0;
}