#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main(int argc, const char* argv[])
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int arr[9] = { 0 };
	for (int i = 0; i < 9; i++) {
		std::cin >> arr[i];
	}

	int max = 0, place = 0;
	for (int i = 0; i < 9; i++) {
		if (max < arr[i]) {
			max = arr[i];
			place = i + 1;
		}
	}
	std::cout << max << "\n" << place;

	return 0;
}