#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main(int argc, const char* argv[])
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int n, m;
	std::cin >> n >> m;

	int** a = new int* [n];
	int** b = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[m];
		b[i] = new int[m];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> b[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << a[i][j] + b[i][j] << " ";
		}
		std::cout << "\n";
	}

	for (int i = 0; i < n; i++) {
		delete[] a[i];
		delete[] b[i];
	}
	delete[] a;
	delete[] b;

	return 0;
}