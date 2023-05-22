#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main(int argc, const char* argv[])
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int n, x;
	std::cin >> n >> x;

	int a;

	for (int i = 0; i < n; i++) {
		std::cin >> a;
		if (x > a) {
			std::cout << a << " ";
		}
	}

	return 0;
}