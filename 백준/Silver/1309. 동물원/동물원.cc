#include <bits/stdc++.h>

using namespace std;

// 사자 우리
int dp[100005];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 우리의 크기
	int n;
	cin >> n;
	dp[0] = 1;
	dp[1] = 3;
	for (int i = 2; i <= n; ++i) {
		dp[i] = dp[i - 2] + dp[i - 1] * 2 >= 9901 ? (dp[i - 2] + dp[i - 1] * 2) % 9901 : dp[i - 2] + dp[i - 1] * 2;
	}
	cout << dp[n];

	return 0;
}