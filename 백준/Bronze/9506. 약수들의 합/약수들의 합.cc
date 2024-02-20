#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (true) {
		int n;
		cin >> n;
		if (n == -1) break;

		vector<int> v;
		for (int i = 1; i * i <= n; ++i) {
			if (i * i == n) {
				v.push_back(i);
				break;
			}
			if (n % i) continue;
			v.push_back(i);
			v.push_back(n / i);
		}
		sort(v.begin(), v.end());

		int sum = 0;
		for (int i = 0; i < (int)v.size() - 1; ++i) sum += v[i];

		if (sum == n) {
			cout << n << " = ";
			for (int i = 0; i < (int)v.size() - 1; ++i) {
				cout << v[i];
				if (i != (int)v.size() - 2) cout << " + ";
			}
			cout << "\n";
		}
		else cout << n << " is NOT perfect.\n";
	}

	return 0;
}