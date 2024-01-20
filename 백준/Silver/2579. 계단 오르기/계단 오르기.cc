#include <bits/stdc++.h>
using namespace std;

int n;
int st[305];
int dp[305][2];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> st[i];
	}

	dp[1][0] = st[1], dp[2][0] = st[2], dp[2][1] = st[1] + st[2];
	for (int i = 3; i <= n; i++) {
		dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + st[i];
		dp[i][1] = dp[i - 1][0] + st[i];
	}

	cout << max(dp[n][0], dp[n][1]);

	return 0;
}