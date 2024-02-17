#include <bits/stdc++.h>

using namespace std;

int mx[4]{ 1,0,-1,0 }, my[4]{ 0,1,0,-1 };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	queue<pair<int, int>> q;

	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m, 0));
	vector<vector<bool>> vis(n, vector<bool>(m, false));

	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		int num;
		cin >> num;
		board[i][j] = num;
		if (num == 2) {
			q.push({ i,j });
			vis[i][j] = true;
			board[i][j] = 0;
		}
	}

	while ((int)q.size()) {
		int curX = q.front().first, curY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int px = curX + mx[i], py = curY + my[i];
			if (px < 0 || px >= n || py < 0 || py >= m) continue;
			if (vis[px][py] || board[px][py] == 0) continue;
			board[px][py] = board[curX][curY] + 1;
			q.push({ px,py });
			vis[px][py] = true;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!vis[i][j] && board[i][j] == 1) board[i][j] = -1;
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}