#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	// n개가 들어오면 1의 최대 개수는 n이고, 00의 최대 개수는 n / 2이다.
	int n;
	cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	if (n == 2) {
		cout << 2;
		return 0;
	}

	int a = 1, b = 2, c = 3;
	for (int i = 3; i <= n; ++i) {
		c = a + b;
		if (c >= 15746) c %= 15746;
		a = b;
		b = c;
	}
	cout << c;

	return 0;
}