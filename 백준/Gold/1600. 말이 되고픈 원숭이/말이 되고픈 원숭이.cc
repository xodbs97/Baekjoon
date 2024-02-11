#include <bits/stdc++.h>

using namespace std;

// 말 움직임 최대 회수
int k;
// 가로, 세로 길이
int w, h;
// 격자판. (y, x, z)로 저장. z는 말의 사용 횟수이다.
vector<vector<vector<int>>> board(205, vector<vector<int>>(205, vector<int>(35)));
// 원숭이 움직임
int mx[4]{ 1,0,-1,0 }, my[4]{ 0,1,0,-1 };
// 말 움직임
int hx[8]{ -2,-2,-1,-1,1,1,2,2 }, hy[8]{ -1,1,-2,2,-2,2,-1,1 };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> k;
	cin >> w >> h;
	// 가로가 1일 때 장애물이 하나라도 있으면 -1, 없으면 h - 1 출력하고 프로그램 종료
	if (w == 1) {
		for (int i = 0; i < h; ++i) {
			int m;
			cin >> m;
			if (m) {
				cout << -1;
				return 0;
			}
		}
		cout << h - 1;
		return 0;
	}
	// 세로가 1일 때 장애물이 하나라도 있으면 -1, 없으면 w - 1 출력하고 프로그램 종료
	if (h == 1) {
		for (int i = 0; i < w; ++i) {
			int m;
			cin >> m;
			if (m) {
				cout << -1;
				return 0;
			}
		}
		cout << w - 1;
		return 0;
	}

	// 격자판 채우기. 장애물은 -1로 저장
	for (int y = 0; y < h; ++y) for (int x = 0; x < w; ++x) {
		int m;
		cin >> m;
		for (int z = 0; z <= k; ++z) {
			if (m) board[y][x][z] = -1;
		}
	}

	// bfs로 풀이. (0, 0)부터 시작해서 (w - 1, h - 1)에 도착하기.
	// queue<tuple> 사용. (x, y, z)로 저장. 격자판은 [y][x][z]로 저장되기 때문에 유의할 것
	queue<tuple<int, int, int>> qq;
	qq.push({ 0,0,0 });
	while (qq.size()) {
		// 현재 위치해있는 좌표
		int x, y, z;
		tie(x, y, z) = qq.front();
		qq.pop();
		// 원숭이의 이동
		for (int i = 0; i < 4; ++i) {
			int px = x + mx[i], py = y + my[i];
			if (px < 0 || px >= w || py < 0 || py >= h) continue;
			if (board[py][px][z] == -1 || board[py][px][z] > 0) continue;
			qq.push({ px,py,z });
			board[py][px][z] = board[y][x][z] + 1;
		}
		// 말의 이동. 이동 횟수를 초과해서 이동할 수는 없다
		if (z < k) {
			for (int i = 0; i < 8; ++i) {
				int px = x + hx[i], py = y + hy[i];
				if (px < 0 || px >= w || py < 0 || py >= h) continue;
				if (board[py][px][z + 1] == -1 || board[py][px][z + 1] > 0) continue;
				qq.push({ px,py,z + 1 });
				board[py][px][z + 1] = board[y][x][z] + 1;
			}
		}
	}

	int ans = 2000000000;
	for (int i = 0; i <= k; ++i) {
		if (board[h - 1][w - 1][i]) ans = min(ans, board[h - 1][w - 1][i]);
	}
	cout << (ans == 2000000000 ? -1 : ans);

	return 0;
}