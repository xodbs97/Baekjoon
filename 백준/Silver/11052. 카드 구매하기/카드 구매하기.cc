#include <bits/stdc++.h>

using namespace std;

// 카드 개수
int n;
// 카드팩 가격
int cost[1005];

int dp[1005];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> cost[i];
	for (int i = 1; i <= n; ++i) {
		int mx = cost[i];
		for (int j = 1; j <= i / 2; ++j) mx = max(mx, dp[j] + dp[i - j]);
		dp[i] = mx;
	}
	cout << dp[n];

	return 0;
}