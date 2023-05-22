#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

int main(int argc, const char* argv[])
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	std::string s;
	int i;
	std::cin >> s >> i;

	std::cout << s[i - 1];

	return 0;
}