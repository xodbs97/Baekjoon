#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main(int argc, const char* argv[])
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int n;
	std::cin >> n;

	int* arr = new int[n];
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	int v;
	std::cin >> v;

	for (int i = 0; i < n; i++) {
		arr[i] == v ? cnt++ : 0;
	}

	std::cout << cnt;

	delete[] arr;
	arr = 0;

	return 0;
}