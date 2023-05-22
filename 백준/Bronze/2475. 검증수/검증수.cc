#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main(int argc, const char* argv[])
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int n = 0, sum = 0;
	
	for (int i = 0; i < 5; i++) {
		std::cin >> n;
		sum += n * n;
	}

	std::cout << sum % 10;

	return 0;
}