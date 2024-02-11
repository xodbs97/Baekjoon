#include <bits/stdc++.h>

using namespace std;

// 격자판
int board[30][30];
// 답들의 모음을 저장하는 배열
int ans[350];
// 상하좌우를 가리키기 쉽도록 만들어주는 배열
int mx[4]{ 1,0,-1,0 }, my[4]{ 0,1,0,-1 };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < n; ++j) board[i][j] = s[j] - '0';
	}

	// 단지 크기를 저장하는 곳을 가리키는 번호
	int idx = 0;
	for (int w = 0; w < n; ++w) for (int h = 0; h < n; ++h) {
		// 단지의 시작
		if (board[w][h]) {
			queue<pair<int, int>> q;
			board[w][h] = 0;
			q.push({ w,h });
			while (q.size()) {
				int cx = q.front().first, cy = q.front().second;
				++ans[idx];
				q.pop();
				for (int i = 0; i < 4; ++i) {
					int px = cx + mx[i], py = cy + my[i];
					if (px < 0 || px >= n || py < 0 || py >= n) continue;
					if (board[px][py] == 0) continue;
					board[px][py] = 0;
					q.push({ px,py });
				}
			}
			++idx;
		}
	}
	sort(ans, ans + idx);
	cout << idx << "\n";
	for (int i = 0; i < idx; ++i) cout << ans[i] << "\n";

	return 0;
}