#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main(int argc, const char* argv[])
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	long long a, b;
	std::cin >> a >> b;

	std::cout << a * a - b * b;

	return 0;
}