#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<ll> mx(n + 1, 0);
	vector<ll> mid(n + 1, 0);
	vector<ll> cnt(n + 1, 0);
	mx[1] = 2;
	mid[1] = 0;
	cnt[1] = 1;
	for (int i = 2; i <= n; ++i) {
		mid[i] = (mid[i - 1] + i * 2 - 2) % 1000000007;
		mx[i] = (mx[i - 1] + (mid[i] + i * 2) % 1000000007 * i % 1000000007) % 1000000007;
		cnt[i] = cnt[i - 1] * i % 1000000007 * i % 1000000007;
	}
	cout << mx[n] << " " << cnt[n];

	return 0;
}