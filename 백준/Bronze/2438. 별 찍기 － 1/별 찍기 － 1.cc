#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int n;

	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			std::cout << "*";
		}
		std::cout << "\n";
	}

	return 0;
}