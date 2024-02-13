#include <bits/stdc++.h>

using namespace std;

// 공간을 작게 차지하기 위해 vector<bool> 사용
vector<vector<bool>> board(55, vector<bool>(55));

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			// W는 true, B는 false로 수정
			if (s[j] == 'B') board[i][j] = false;
			else board[i][j] = true;
		}
	}

	int ans = 1000000000;
	for (int i = 0; i <= n - 8; ++i) {
		for (int j = 0; j <= m - 8; ++j) {
			// 각각 true와 false로 시작하는 2개의 필터 사용, 각각의 보드판과의 차이를 비교해 둘 중 더 적은 값을 채택
			int d1 = 0, d2 = 0, dif = 0;
			bool f1 = true, f2 = false;
			for (int row = i + 0; row < i + 8; ++row) {
				f1 = !f1;
				f2 = !f2;
				for (int col = j + 0; col < j + 8; ++col) {
					if (f1 != board[row][col]) ++d1;
					if (f2 != board[row][col]) ++d2;
					f1 = !f1;
					f2 = !f2;
				}
			}
			dif = min(d1, d2);
			ans = min(ans, dif);
		}
	}
	cout << ans;

	return 0;
}