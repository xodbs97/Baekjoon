#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main(int argc, const char* argv[])
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int A, B;

	while (std::cin >> A >> B) {
		std::cout << A + B << "\n";
	}

	return 0;
}