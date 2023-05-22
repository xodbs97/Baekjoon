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

	int r;
	std::string s;
	for (int i = 0; i < t; i++) {
		std::cin >> r >> s;
		for (int j = 0; j < s.length(); j++) {
			for (int k = 0; k < r; k++) {
				std::cout << s[j];
			}
		}
		std::cout << "\n";
	}

	return 0;
}