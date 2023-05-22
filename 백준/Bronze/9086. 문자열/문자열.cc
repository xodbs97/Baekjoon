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

	std::string s;

	for (int i = 0; i < t; i++) {
		std::cin >> s;
		std::cout << s[0] << s[s.length() - 1] << "\n";
	}

	return 0;
}