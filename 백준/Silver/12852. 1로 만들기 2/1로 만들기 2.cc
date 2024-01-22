#include <bits/stdc++.h>
using namespace std;

int n;
int d[1000005], h[1000005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	d[2] = 1, h[2] = 1;
	d[3] = 1, h[3] = 1;

	cin >> n;
	for (int i = 4; i <= n; i++) {
		d[i] = d[i - 1] + 1;
		h[i] = i - 1;
		if (i % 2 == 0 && d[i] > d[i / 2] + 1) {
			d[i] = d[i / 2] + 1;
			h[i] = i / 2;
		}
		if (i % 3 == 0 && d[i] > d[i / 3] + 1) {
			d[i] = d[i / 3] + 1;
			h[i] = i / 3;
		}
	}
	cout << d[n] << "\n";
	while (n) {
		cout << n << " ";
		n = h[n];
	}

	return 0;
}