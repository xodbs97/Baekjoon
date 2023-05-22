#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

int main(int argc, const char* argv[])
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int t;
	std::cin >> t;

	std::string str;
	int point = 1, sum = 0;
	for (int i = 0; i < t; i++) {
		std::cin >> str;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == 'O') {
				sum += point++;
			}
			else {
				point = 1;
			}
		}

		std::cout << sum << "\n";
		sum = 0;
		point = 1;
	}

	return 0;
}