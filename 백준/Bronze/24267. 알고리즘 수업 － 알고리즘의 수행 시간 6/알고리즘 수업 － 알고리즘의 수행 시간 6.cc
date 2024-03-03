#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin >> n;

	vector<ll> dp(n, 0);
	for (ll i = 1; i <= n - 2; ++i) dp[i] = i * (i + 1) / 2;
	ll ans = 0;
	for (int i = 1; i <= n - 2; ++i) ans += dp[i];
	cout << ans << "\n" << 3;

	return 0;
}