#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp(31, vector<int>(31));

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1; i <= 30; ++i) dp[1][i] = i;
	for (int i = 2; i <= 30; ++i) {
		for (int j = i; j <= 30; ++j) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		cout << dp[n][m] << "\n";
	}

	return 0;
}