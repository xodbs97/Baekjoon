#include <bits/stdc++.h>

using namespace std;

vector<int> dp(5001);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dp[3] = 1;
	dp[5] = 1;

	int n;
	cin >> n;
	for (int i = 6; i <= n; ++i) {
		if (dp[i - 5] && dp[i - 3]) dp[i] = min(dp[i - 5], dp[i - 3]) + 1;
		else if (dp[i - 5]) dp[i] = dp[i - 5] + 1;
		else if (dp[i - 3]) dp[i] = dp[i - 3] + 1;
	}
	cout << (dp[n] ? dp[n] : -1);

	return 0;
}