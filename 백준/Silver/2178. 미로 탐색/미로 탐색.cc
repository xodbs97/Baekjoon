#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int** box = new int* [n];
	int** dist = new int* [n];
	for (int i = 0; i < n; i++) {
		box[i] = new int[m];
		dist[i] = new int[m];
		for (int j = 0; j < m; j++) dist[i][j] = 0;
	}
	int dx[4]{ 1,0,-1,0 }, dy[4]{ 0,1,0,-1 };

	for (int i = 0; i < n; i++) {
		string num;
		cin >> num;
		for (int j = 0; j < m; j++) {
			box[i][j] = num[j] - '0';
			if (box[i][j] == 1) dist[i][j] = -1;
		}
	}

	dist[0][0] = 1;
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int px = cur.X + dx[i], py = cur.Y + dy[i];
			if (px < 0 || px >= n || py < 0 || py >= m) continue;
			if (dist[px][py] >= 0) continue;
			dist[px][py] = dist[cur.X][cur.Y] + 1;
			q.push({ px,py });
		}
	}

	int ans = dist[n - 1][m - 1];
	cout << ans;

	for (int i = 0; i < n; i++) {
		delete[] box[i];
		delete[] dist[i];
	}
	delete[] box;
	delete[] dist;
	return 0;
}