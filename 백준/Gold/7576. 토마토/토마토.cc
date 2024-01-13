#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> m >> n;

	int** box = new int* [n];
	int** days = new int* [n];
	for (int i = 0; i < n; i++) {
		box[i] = new int[m];
		days[i] = new int[m];
		for (int j = 0; j < m; j++) days[i][j] = 0;
	}
	int dx[4]{ 1,0,-1,0 }, dy[4]{ 0,1,0,-1 };

	queue<pair<int, int>> tomato;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		cin >> box[i][j];
		if (box[i][j] == 0) days[i][j] = -1;
		if (box[i][j] == 1) tomato.push({ i,j });
	}

	while (!tomato.empty()) {
		auto cur = tomato.front(); tomato.pop();
		for (int dir = 0; dir < 4; dir++) {
			int px = cur.X + dx[dir], py = cur.Y + dy[dir];
			if (px < 0 || px >= n || py < 0 || py >= m) continue;
			if (days[px][py] >= 0) continue;
			days[px][py] = days[cur.X][cur.Y] + 1;
			tomato.push({ px,py });
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		if (days[i][j] == -1) {
			cout << -1;
			return 0;
		}
		ans = max(ans, days[i][j]);
	}
	cout << ans;

	for (int i = 0; i < n; i++) {
		delete[] box[i];
		delete[] days[i];
	}
	delete[] box;
	delete[] days;
	return 0;
}
