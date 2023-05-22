#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main(int argc, const char* argv[])
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int num;
	std::cin >> num;
	do {
		if (num / 10000) {
			if (num / 10000 != num % 10) {
				std::cout << "no\n";
			}
			else {
				if ((num / 1000) % 10 == (num % 100) / 10) {
					std::cout << "yes\n";
				}
				else {
					std::cout << "no\n";
				}
			}
		}
		else if (num / 1000) {
			if (num / 1000 != num % 10) {
				std::cout << "no\n";
			}
			else {
				if ((num / 100) % 10 == (num % 100) / 10) {
					std::cout << "yes\n";
				}
				else {
					std::cout << "no\n";
				}
			}
		}
		else if (num / 100) {
			if (num / 100 != num % 10) {
				std::cout << "no\n";
			}
			else {
				std::cout << "yes\n";
			}
		}
		else if (num / 10) {
			if (num / 10 != num % 10) {
				std::cout << "no\n";
			}
			else {
				std::cout << "yes\n";
			}
		}
		else {
			std::cout << "yes\n";
		}

		std::cin >> num;
	} while (num);

	return 0;
}
