#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<bool> primes(1000001, true);
	primes[0] = false;
	primes[1] = false;

	for (int i = 2; i * i <= 1000000; ++i) {
		if (primes[i]) {
			for (int j = i * i; j <= 1000000; j += i) primes[j] = false;
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		int ans = 0;
		for (int i = 2; i <= n / 2; ++i) {
			if (primes[i] && primes[n - i]) ++ans;
		}

		cout << ans << "\n";
	}

	return 0;
}