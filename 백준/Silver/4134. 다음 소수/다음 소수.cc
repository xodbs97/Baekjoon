#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<int> findPrimes(int n) {
	vector<bool> chk(n + 1, false);
	vector<int> pn;

	for (int i = 2; i <= sqrt(n); ++i) {
		if (!chk[i]) {
			pn.push_back(i);
			for (int j = i * i; j <= n; j += i) chk[j] = true;
		}
	}

	for (int i = sqrt(n) + 1; i <= n; ++i) {
		if (!chk[i]) pn.push_back(i);
	}

	return pn;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> primes = findPrimes(68000);

	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		if (n <= 2) {
			cout << "2\n";
			continue;
		}

		while (true) {
			bool find = true;
			for (int prime : primes) {
				if ((ll)prime * prime > n) break;
				if (n % prime == 0) {
					find = false;
					break;
				}
			}

			if (find) {
				cout << n << "\n";
				break;
			}
			++n;
		}
	}

	return 0;
}