#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[55][55];
int dx[4]{ 0,1,0,-1 }, dy[4]{ 1,0,-1,0 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int ans = 0;
		int m, n, k;
		cin >> m >> n >> k;
		while (k--) {
			int x, y;
			cin >> x >> y;
			board[x][y] = 1;
		}
		queue<pair<int, int>> que;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 1) {
					++ans;
					que.push({ i,j });
					board[i][j] = 0;
					while (que.size()) {
						for (int k = 0; k < 4; k++) {
							int px = que.front().X + dx[k], py = que.front().Y + dy[k];
							if (px < 0 || px >= m || py < 0 || py >= n) continue;
							if (board[px][py] == 0) continue;
							que.push({ px,py });
							board[px][py] = 0;
						}
						que.pop();
					}
				}
			}
		}
		cout << ans << "\n";
		fill(&board[0][0], &board[54][55], 0);
	}

	return 0;
}