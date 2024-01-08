#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int sum = 0;
	int min = 100;
	int r = 7;
	while (r--) {
		int n;
		cin >> n;
		if (n % 2) {
			sum += n;
			min = n < min ? n : min;
		}
	}
	if (!sum) {
		cout << -1;
	}
	else {
		cout << sum << "\n" << min;
	}

	return 0;
}