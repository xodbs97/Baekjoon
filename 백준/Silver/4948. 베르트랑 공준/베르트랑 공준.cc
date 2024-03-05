#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<bool> primes(250001, true);
	primes[0] = false;
	primes[1] = false;

	for (int i = 2; i * i <= 250000; ++i) {
		if (primes[i]) {
			for (int j = i * i; j <= 250000; j += i) primes[j] = false;
		}
	}

	while (true) {
		int n;
		cin >> n;
		if (n == 0) return 0;

		int ans = 0;
		for (int i = n + 1; i <= n * 2; ++i) if (primes[i]) ++ans;

		cout << ans << "\n";
	}

	return 0;
}