#include <bits/stdc++.h>

using namespace std;

// 동전 종류 개수, 총합
int n, k;
// 동전의 종류를 저장하는 배열. 오름차순으로 정렬.
int coins[105];
// dp로 풀이
int dp[10005];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> coins[i];
	sort(coins, coins + n);
	// 0을 만들 수 있는 경우는 1가지이다.
	dp[0] = 1;
	for (int i = 0; i < n; ++i) {
		int coin = coins[i];
		for (int j = coin; j <= k; ++j) {
			dp[j] += dp[j - coin];
		}
	}
	cout << dp[k];

	return 0;
}