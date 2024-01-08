#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int arr[10]{};
	while (n) {
		++arr[n % 10];
		n /= 10;
	}
	int t = arr[6] + arr[9];
	if (t % 2) {
		arr[6] = t / 2 + 1;
		arr[9] = t / 2 + 1;
	}
	else {
		arr[6] = t / 2;
		arr[9] = t / 2;
	}
	int max = 0;
	for (int i = 0; i < 10; i++) {
		max = arr[i] > max ? arr[i] : max;
	}
	cout << max;

	return 0;
}