#include <bits/stdc++.h>
using namespace std;

int m, n, h; // 가로, 세로, 높이
int box[105][105][105]; // 높이, 세로, 가로
bool ch[105][105][105]; // 방문한 지역 저장
int dx[4]{ 1,0,-1,0 }, dy[4]{ 0,1,0,-1 }, dz[2]{ 1,-1 }; // 6 방향 좌표
queue<tuple<int, int, int>> tomato; // 익은 토마토 정보

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	bool all_rippen = true;
	cin >> m >> n >> h; // 가로 세로 높이
	for (int floor = 0; floor < h; floor++) { // 0층 부터 차례대로 입력
		for (int length = 0; length < n; length++) { // 세로
			for (int width = 0; width < m; width++) { // 가로
				int i;
				cin >> i;
				if (i == 1) {
					tomato.push({ floor,length,width });
					ch[floor][length][width] = true;
				}
				else if (i == 0) all_rippen = false;
				box[floor][length][width] = i;
			}
		}
	}
	if (all_rippen) { // 익지 않은 토마토가 없을 경우에
		cout << 0;
		return 0;
	}

	while (tomato.size()) {
		int f = get<0>(tomato.front());
		int y = get<1>(tomato.front());
		int x = get<2>(tomato.front());
		tomato.pop();
		for (int i = 0; i < 2; i++) {
			int px = x;
			int py = y;
			int pz = f + dz[i];
			if (pz < 0 || pz >= h) continue; // 범위를 벗어나면
			if (ch[pz][py][px]) continue; // 이미 확인이 된 토마토라면
			if (box[pz][py][px] < 0) continue; // 비어있는 칸이라면
			box[pz][py][px] = box[f][y][x] + 1; // 다음 날로 업데이트
			tomato.push({ pz,py,px });
			ch[pz][py][px] = true;
		}
		for (int i = 0; i < 4; i++) {
			int px = x + dx[i];
			int py = y + dy[i];
			int pz = f;
			if (px < 0 || px >= m || py < 0 || py >= n) continue; // 범위를 벗어나면
			if (ch[pz][py][px]) continue; // 이미 확인이 된 토마토라면
			if (box[pz][py][px] < 0) continue; // 비어있는 칸이라면
			box[pz][py][px] = box[f][y][x] + 1; // 다음 날로 업데이트
			tomato.push({ pz,py,px });
			ch[pz][py][px] = true;
		}
	}

	int day = 0;
	for (int floor = 0; floor < h; floor++) {
		for (int length = 0; length < n; length++) {
			for (int width = 0; width < m; width++) {
				if (box[floor][length][width] == 0) {
					cout << -1;
					return 0;
				}
				day = max(day, box[floor][length][width] - 1);
			}
		}
	}
	cout << day;

	return 0;
}