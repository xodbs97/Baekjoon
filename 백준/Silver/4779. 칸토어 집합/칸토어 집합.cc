#include <bits/stdc++.h>

using namespace std;

vector<string> dp(13);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dp[0] = "-";
	for (int i = 1; i <= 12; ++i) {
		int len = (int)dp[i - 1].size();
		dp[i] += dp[i - 1];
		while (len--) dp[i] += " ";
		dp[i] += dp[i - 1];
	}

	// 0 ~ 12
	int n;
	while (cin >> n) cout << dp[n] << "\n";

	return 0;
}