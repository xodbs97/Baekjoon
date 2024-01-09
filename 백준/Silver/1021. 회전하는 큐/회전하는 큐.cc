#include <iostream>

using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;

	int* a = new int[m];

	for (int i = 0; i < m; i++) {
		int p;
		cin >> p;
		a[i] = p;
	}
	for (int i = 0; i < m - 1; i++) for (int j = i + 1; j < m; j++) if (a[j] > a[i]) --a[j];

	int sum = 0;
	int idx = 1;
	for (int i = 0; i < m; i++) {
		int d = a[i] > idx ? a[i] - idx : idx - a[i];
		idx = a[i];
		sum += d < n - d ? d : n - d;
		--n;
	}
	cout << sum;

	delete[] a;
	return 0;
}