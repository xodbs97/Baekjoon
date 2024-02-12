#include <bits/stdc++.h>

using namespace std;

int dp[105][10];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 1; i <= 9; ++i) dp[1][i] = 1;

	int n;
	cin >> n;

	for (int i = 2; i <= n; ++i) {
		dp[i][0] = dp[i - 1][1];
		for (int j = 1; j <= 8; ++j) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1] >= 1000000000 ? (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000 : dp[i - 1][j - 1] + dp[i - 1][j + 1];
		dp[i][9] = dp[i - 1][8];
	}
	int ans = 0;
	for (int i = 0; i <= 9; ++i) {
		ans += dp[n][i];
		if (ans >= 1000000000) ans %= 1000000000;
	}
	cout << ans;

	return 0;
}