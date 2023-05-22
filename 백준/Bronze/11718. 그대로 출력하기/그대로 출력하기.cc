#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

int main(int argc, const char* argv[])
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	std::string s;

	while (true) {
		std::getline(std::cin, s);
		if (s == "") {
			break;
		}
		std::cout << s << "\n";
	}

	return 0;
}