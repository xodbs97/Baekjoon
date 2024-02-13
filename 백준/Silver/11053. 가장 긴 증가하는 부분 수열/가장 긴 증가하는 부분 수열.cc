#include <bits/stdc++.h>

using namespace std;

// 수열을 저장하는 배열
int num[1005];
// dp[i]: 1 ~ i 번째 수열로 만들 수 있는 조건을 만족하는 부분수열 중 가장 긴 부분수열의 길이를 저장하는 배열
int dp[1005];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> num[i];

	// 답을 저장할 변수
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		// 자기 자신만을 가지는 부분수열의 길이는 1이다.
		dp[i] = 1;
		// 1부터 i - 1까지의 수열의 원소들을 비교한다.
		for (int j = 1; j < i; ++j) {
			// 만약 j번째 수가 i번째 수보다 작다면(원래 j번째 수로 끝난 수열에 i번째 수를 포함을 시킬 수 있다면)
			if (num[i] > num[j]) {
				// 현재 i번째 수까지 포함한 수열의 부분수열의 최대길이는 j번째 수열의 최대 길이 + 1 혹은 기존의 길이 중 최댓값으로 갱신하면 된다.
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans;

	return 0;
}