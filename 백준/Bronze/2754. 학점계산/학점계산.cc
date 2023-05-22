#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

int main(int argc, const char* argv[])
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	std::cout.precision(1);
	std::cout << std::fixed;

	std::string str;
	std::cin >> str;

	double n = 0.0;

	n += 69 - str[0];
	if (n > 0) {
		if (str[1] == 43) {
			n += 0.3;
		}
		else if (str[1] == 45) {
			n -= 0.3;
		}
		std::cout << n;
	}
	else {
		std::cout << 0.0;
	}

	return 0;
}