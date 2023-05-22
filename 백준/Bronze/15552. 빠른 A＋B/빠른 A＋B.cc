#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main(int argc, const char* argv[])
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int t;
	std::cin >> t;

	int a, b;
	for (int i = 0; i < t; i++) {
		std::cin >> a >> b;

		std::cout << a + b << "\n";
	}

	return 0;
}