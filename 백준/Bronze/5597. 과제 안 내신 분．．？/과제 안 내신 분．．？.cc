#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main(int argc, const char* argv[])
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int arr[31] = { 0 };

	int n;
	for (int i = 0; i < 28; i++) {
		std::cin >> n;
		arr[n] = 1;
	}	

	for (int i = 1; i <= 30; i++) {
		if (arr[i] == 0) {
			std::cout << i << "\n";
		}
	}

	return 0;
}