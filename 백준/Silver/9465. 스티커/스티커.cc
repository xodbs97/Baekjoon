#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>> v(2, vector<int>(n, 0));
		vector<vector<int>> dp(2, vector<int>(n, 0));
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < n; ++j) cin >> v[i][j];
		}
		// 스티커가 2개 밖에 없는 경우
		if (n == 1) {
			cout << (v[0][0] > v[1][0] ? v[0][0] : v[1][0]) << "\n";
			continue;
		}
		// 스티커가 4개 밖에 없는 경우
		if (n == 2) {
			cout << (v[0][0] + v[1][1] > v[1][0] + v[0][1] ? v[0][0] + v[1][1] : v[1][0] + v[0][1]) << "\n";
			continue;
		}
		// 그 이상의 스티커가 있는 경우
		dp[0][0] = v[0][0];
		dp[1][0] = v[1][0];
		dp[0][1] = v[1][0] + v[0][1];
		dp[1][1] = v[0][0] + v[1][1];
		for (int i = 2; i < n; ++i) {
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + v[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + v[1][i];
		}
		cout << (dp[0][n - 1] > dp[1][n - 1] ? dp[0][n - 1] : dp[1][n - 1]) << "\n";
	}

	return 0;
}