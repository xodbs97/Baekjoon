#include <bits/stdc++.h>
using namespace std;

int n, k; // n: 물품의 수, k: 가방의 한도
int p[105][2]; // 0: 무게, 1: 가치
int dp[105][100005]; // 해당 공간은 [n개의 물품과][현재 가방의 남은 한도]에서의 최적해이다.

void func() {
	for (int num = 1; num <= n; num++) {
		for (int space = 1; space <= k; space++) {
			if (p[num][0] > space) dp[num][space] = dp[num - 1][space]; // 현 물품의 무게가 남은 무게를 초과하는 경우: 넣지 않았을 때의 최적해와 같다.
			else dp[num][space] = max(dp[num - 1][space - p[num][0]] + p[num][1], dp[num - 1][space]); // 넣을 수 있는 경우: 넣고 남은 공간에서의 최적해와 넣지 않았을 때의 최적해 중 더 큰 값이 현 상황에서의 최적해이다.
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> p[i][0] >> p[i][1];
	func();
	cout << dp[n][k];

	return 0;
}