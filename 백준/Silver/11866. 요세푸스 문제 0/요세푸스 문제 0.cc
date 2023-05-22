#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main(int argc, const char* argv[])
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int n, k;
	std::cin >> n >> k;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}

	int place = 0, cnt = 0, check = 0;
	std::cout << "<";
	while (true) {
		if (place == n) {
			place = 0;
		}

		if (arr[place] != 0) {
			cnt++;
		}

		if (cnt == k) {
			std::cout << arr[place];
			arr[place] = 0;
			cnt = 0;
			check++;

			if (check == n) {
				break;
			}

			std::cout << ", ";
		}
		place++;
	}
	std::cout << ">";
	
	delete[] arr;

	return 0;
}