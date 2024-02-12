#include <bits/stdc++.h>

using namespace std;

// dp[수의 길이][1의 자릿수] 일 때, 가질 수 있는 경우의 수를 저장하는 배열
int dp[1005][10];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	// 수의 길이가 1이면 항상 1개는 오름차순이므로 1 저장
	for (int i = 0; i < 10; ++i) dp[1][i] = 1;
	// 수의 길이가 n이고 1의 자리가 0이라면 가능한 수는 항상 1
	for (int i = 2; i <= n; ++i) dp[i][0] = 1;

	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j < 10; ++j) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j] >= 10007 ? dp[i][j - 1] + dp[i - 1][j] % 10007 : dp[i][j - 1] + dp[i - 1][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < 10; ++i) {
		ans += dp[n][i];
		if (ans >= 10007) ans %= 10007;
	}
	cout << ans;

	return 0;
}