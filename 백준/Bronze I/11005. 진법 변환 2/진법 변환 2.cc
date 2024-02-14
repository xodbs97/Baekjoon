#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,m;
	cin >> n >> m;
	int number[35];
	int idx = 0;
	while (n) {
		number[idx] = n % m;
		n /= m;
		++idx;
	}

	for (int i = idx - 1; i >= 0; --i) {
		if (number[i] >= 10) cout << (char)('A' + number[i] - 10);
		else cout << number[i];
	}

	return 0;
}