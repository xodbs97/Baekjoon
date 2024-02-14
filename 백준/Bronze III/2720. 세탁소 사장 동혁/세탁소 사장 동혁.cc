#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int c;
		cin >> c;
		int q = c / 25;
		cout << q << " ";
		if (c % 25 == 0) {
			cout << "0 0 0\n";
			continue;
		}
		c %= 25;
		int d = c / 10;
		cout << d << " ";
		if (c % 10 == 0) {
			cout << "0 0\n";
			continue;
		}
		c %= 10;
		int n = c / 5;
		cout << n << " ";
		if (c % 5 == 0) {
			cout << "0\n";
			continue;
		}
		c %= 5;
		cout << c << "\n";
	}

	return 0;
}