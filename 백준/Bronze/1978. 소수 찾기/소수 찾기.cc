#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int ans = 0;
	while (n--) {
		int k;
		cin >> k;
		if (k == 1) continue;
		bool is_prime = true;
		for (int i = 2; i * i <= k; i++) {
			if (k % i) continue;
			is_prime = false;
			break;
		}
		if (is_prime) ++ans;
	}
	cout << ans;

	return 0;
}