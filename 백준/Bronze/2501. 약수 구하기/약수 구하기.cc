#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	if (k >= 200) {
		cout << 0;
		return 0;
	}
    
	vector<int> v(200, 0);
	int idx = 1;
	for (int i = 1; i * i <= n; ++i) {
		if (n % i) continue;
		v[idx++] = i;
	}

	if (v[idx - 1] * v[idx - 1] == n) for (int i = idx - 2; i >= 1; --i) v[idx++] = n / v[i];
	else for (int i = idx - 1; i >= 1; --i) v[idx++] = n / v[i];
	cout << v[k];

	return 0;
}