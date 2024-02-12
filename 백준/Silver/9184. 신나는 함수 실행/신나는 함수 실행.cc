#include <bits/stdc++.h>

using namespace std;

// 재귀로 풀이가 불가능하므로 dp를 사용한다. w(a,b,c)는 dp[a][b][c] 이다.
// a,b,c 중 어떤 수라도 0이라면 그 수는 1이고, a,b,c 중 어떤 수라도 21 이상이라면 그 값은 w(20,20,20)과 같고 이는 dp[20][20][20]에 저장되어있다.
int dp[21][21][21];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

    // dp[][][] 내용 채워주기
	for (int i = 0; i <= 20; ++i) {
		for (int j = 0; j <= 20; ++j) {
			dp[0][i][j] = 1;
			dp[i][0][j] = 1;
			dp[i][j][0] = 1;
		}
	}
	for (int i = 1; i <= 20; ++i) {
		for (int j = 1; j <= 20; ++j) {
			for (int k = 1; k <= 20; ++k) {
				if (i < j && j < k) {
					dp[i][j][k] = dp[i][j][k-1] + dp[i][j - 1][k - 1] - dp[i][j - 1][k];
				}
				else {
					dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] - dp[i - 1][j - 1][k - 1];
				}
			}
		}
	}

	while (true) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		cout << "w(" << a << ", " << b << ", " << c << ") = ";
		if (a <= 0 || b <= 0 || c <= 0) {
			cout << 1 << "\n";
			continue;
		}
		if (a > 20 || b > 20 || c > 20) {
			cout << dp[20][20][20] << "\n";
			continue;
		}
		cout << dp[a][b][c] << "\n";
	}

	return 0;
}