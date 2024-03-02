#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<ll>> dp(1005, vector<ll>(1005, 0));
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 2;
	dp[3][3] = 1;

	for (int i = 4; i <= 1000; ++i) {
		for (int j = 1; j <= i; ++j) {
			dp[i][j] = (dp[i - 3][j - 1] + dp[i - 2][j - 1] + dp[i - 1][j - 1]) % 1000000009;
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		cout << dp[n][m] << '\n';
	}

	return 0;
}