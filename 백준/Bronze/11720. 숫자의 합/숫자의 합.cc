#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main(int argc, const char* argv[])
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int n;
	std::cin >> n;

	char* num = new char[n];
	std::cin >> num;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += num[i] - '0';
	}
	std::cout << sum;

	delete[] num;

	return 0;
}