#include <bits/stdc++.h>
using namespace std;

int money[15];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> money[i];

	int cnt = 0;
	while (k) {
		if (money[n] > k) {
			--n;
			continue;
		}
		k -= money[n];
		++cnt;
	}
	cout << cnt;

	return 0;
}