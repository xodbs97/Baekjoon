#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

char board[1002][1002];
int jihun[1002][1002];
int fire[1002][1002];
int n, m, dx[4]{ 1,0,-1,0 }, dy[4]{ 0,1,0,-1 };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	queue<pair<int, int>> jq;
	queue<pair<int, int>> fq;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
		cin >> board[i][j];
		if (board[i][j] == 'J') {
			jq.push({ i,j });
			jihun[i][j] = 1;
			fire[i][j] = -1;
		}
		if (board[i][j] == 'F') {
			fq.push({ i,j });
			fire[i][j] = 0;
			jihun[i][j] = -1;
		}
		if (board[i][j] == '.') {
			jihun[i][j] = -1;
			fire[i][j] = -1;
		}
	}
	for (int i = 0; i <= n + 1; i++) {
		jihun[i][0] = -1;
		jihun[i][m + 1] = -1;
		fire[i][0] = 1000;
		fire[i][m + 1] = 1000;
	}
	for (int j = 0; j <= m + 1; j++) {
		jihun[0][j] = -1;
		jihun[n + 1][j] = -1;
		fire[0][j] = 1000;
		fire[n + 1][j] = 1000;
	}

	if (fq.empty()) {
		while (!jq.empty()) {
			auto cur = jq.front();
			jq.pop();
			if (cur.X == 0 || cur.X == n + 1 || cur.Y == 0 || cur.Y == m + 1) {
				int ans = 1000;
				for (int i = 0; i <= n + 1; i++) {
					if (jihun[i][0] > 0) ans = min(ans, jihun[i][0]);
					if (jihun[i][m + 1] > 0) ans = min(ans, jihun[i][m + 1]);
				}
				for (int j = 0; j <= m + 1; j++) {
					if (jihun[0][j] > 0) ans = min(ans, jihun[0][j]);
					if (jihun[n + 1][j] > 0) ans = min(ans, jihun[n + 1][j]);
				}
				cout << ans - 1;
				return 0;
			}
			for (int i = 0; i < 4; i++) {
				int px = cur.X + dx[i], py = cur.Y + dy[i];
				if (px<0 || px>n + 1 || py<0 || py>m + 1) continue;
				if (jihun[px][py] >= 0) continue;
				jihun[px][py] = jihun[cur.X][cur.Y] + 1;
				jq.push({ px,py });
			}
		}
	}
	else {
		while (!fq.empty()) {
			auto cur = fq.front();
			fq.pop();
			for (int i = 0; i < 4; i++) {
				int px = cur.X + dx[i], py = cur.Y + dy[i];
				if (px<1 || px>n || py<1 || py>m) continue;
				if (fire[px][py] >= 0) continue;
				fire[px][py] = fire[cur.X][cur.Y] + 1;
				fq.push({ px,py });
			}
		}

		while (!jq.empty()) {
			auto cur = jq.front();
			jq.pop();
			if (cur.X == 0 || cur.X == n + 1 || cur.Y == 0 || cur.Y == m + 1) {
				int ans = 1000;
				for (int i = 0; i <= n + 1; i++) {
					if (jihun[i][0] > 0) ans = min(ans, jihun[i][0]);
					if (jihun[i][m + 1] > 0) ans = min(ans, jihun[i][m + 1]);
				}
				for (int j = 0; j <= m + 1; j++) {
					if (jihun[0][j] > 0) ans = min(ans, jihun[0][j]);
					if (jihun[n + 1][j] > 0) ans = min(ans, jihun[n + 1][j]);
				}
				cout << ans - 1;
				return 0;
			}
			for (int i = 0; i < 4; i++) {
				int px = cur.X + dx[i], py = cur.Y + dy[i];
				if (px<0 || px>n + 1 || py<0 || py>m + 1) continue;
				if (jihun[px][py] >= 0) continue;
				if (jihun[cur.X][cur.Y] >= fire[px][py]) {
					jihun[px][py] = 0;
					continue;
				}
				jihun[px][py] = jihun[cur.X][cur.Y] + 1;
				jq.push({ px,py });
			}
		}
	}

	cout << "IMPOSSIBLE";
	return 0;
}