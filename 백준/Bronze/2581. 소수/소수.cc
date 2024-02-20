#include <bits/stdc++.h>

using namespace std;

vector<bool> primes(10001, true);

void findPrimeNum(int n) {
	primes[1] = false;

	for (int i = 2; i <= n; ++i) {
		if (!primes[i]) continue;

		int k = i;
		int j = i;
		while (k * j <= n) primes[k * j++] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, n;
	cin >> m >> n;
	findPrimeNum(n);
	int mn = 0, sum = 0;
	bool first = true;
	for (int i = m; i <= n; ++i) {
		if (primes[i]) {
			if (first) {
				mn = i;
				first = false;
			}
			sum += i;
		}
	}
	if (mn) cout << sum << "\n" << mn;
	else cout << -1;

	return 0;
}