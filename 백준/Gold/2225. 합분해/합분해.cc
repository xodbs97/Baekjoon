#include <bits/stdc++.h>

using namespace std;

// [수의 사용 횟수][만들어야 할 수]
int dp[205][205];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 정수 종류, 더하는 횟수
	int n, k;
	cin >> n >> k;
	for (int i = 0; i <= n; ++i) dp[1][i] = 1;
	for (int i = 2; i <= k; ++i) dp[i][0] = 1;

	for (int i = 2; i <= k; ++i) {
		for (int j = 1; j <= n; ++j) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] >= 1000000000 ? (dp[i - 1][j] + dp[i][j - 1]) % 1000000000 : dp[i - 1][j] + dp[i][j - 1];
		}
	}
	cout << dp[k][n];

	return 0;
}