#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

int EuclideanAlgorithm(int a, int b);

int main(int argc, const char* argv[])
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int a, b;
	std::cin >> a >> b;
	int gcd = EuclideanAlgorithm(a, b);
	int lcm = a * b / gcd;

	std::cout << gcd << "\n" << lcm;

	return 0;
}

int EuclideanAlgorithm(int a, int b)
{
	if (a % b == 0) {
		return b;
	}
	else {
		return EuclideanAlgorithm(b, a % b);
	}
}