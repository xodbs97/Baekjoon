#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	arr[2] = 1, arr[3] = 1;
	cin >> n;
	for (int i = 4; i <= n; i++) {
		if (i % 2 == 0) {
			arr[i] = (i % 3 == 0) ? min(min(arr[i / 2] + 1, arr[i / 3] + 1), arr[i - 1] + 1) : min(arr[i / 2] + 1, arr[i - 1] + 1);
		}
		else {
			arr[i] = (i % 3 == 0) ? min(arr[i / 3] + 1, arr[i - 1] + 1) : arr[i - 1] + 1;
		}
	}
	cout << arr[n];

	return 0;
}