#include <bits/stdc++.h>
using namespace std;

int dp[50][2];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	dp[0][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= 40; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}

	int n;
	cin >> n;
	while (n--) {
		int i;
		cin >> i;
		cout << dp[i][0] << " " << dp[i][1] << "\n";
	}
    
	return 0;
}