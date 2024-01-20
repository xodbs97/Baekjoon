#include <bits/stdc++.h>
using namespace std;

int n;
int rgb[1005][3];
int dp[1005][3];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		int r, g, b;
		cin >> r >> g >> b;
		rgb[i][0] = r, rgb[i][1] = g, rgb[i][2] = b;
	}

	dp[1][0] = rgb[1][0], dp[1][1] = rgb[1][1], dp[1][2] = rgb[1][2];
	for (int i = 2; i <= n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rgb[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rgb[i][2];
	}

	cout << min({ dp[n][0],dp[n][1],dp[n][2] });

	return 0;
}