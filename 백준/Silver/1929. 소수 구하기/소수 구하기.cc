#include <bits/stdc++.h>
using namespace std;

vector<int> sieve_of_eratosthenes(int n) {
	vector<int> primes;
	vector<bool> state(n + 1, true);
	state[1] = false;
	for (int i = 2; i * i <= n; i++) {
		if (!state[i]) continue;
		for (int j = i * i; j <= n; j += i) state[j] = false;
	}
	for (int i = 2; i <= n; i++) if (state[i]) primes.push_back(i);

	return primes;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> v = sieve_of_eratosthenes(m);
	for (int i : v) if (i >= n) cout << i << "\n";

	return 0;
}