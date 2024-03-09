#include <bits/stdc++.h>

using namespace std;

// 터진 풍선을 확인하는 벡터
vector<bool> vis(1005);
// 각 풍선의 이동 방향과 횟수를 저장하는 벡터
vector<int> k(1005);
// 초기 풍선의 개수
int n;

// 이동 함수 
// 인자: 방향, 현재 위치, 이동해야할 횟수
// 반환값: 터뜨릴 풍선의 위치
int moving(bool dir, int cur, int num) {
	int res = cur + (dir ? 1 : -1);

	int cnt = 0;
	// 오른쪽
	if (dir) {
		while (true) {
			if (res > n) res = 0;
			if (vis[res]) {
				++res;
				continue;
			}
			++cnt;
			if (cnt == num) break;
			++res;
		}
	}
	// 왼쪽
	else {
		while (true) {
			if (res == 0) res = n;
			if (vis[res]) {
				--res;
				continue;
			}
			++cnt;
			if (cnt == num) break;
			--res;
		}
	}

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> k[i];
	vis[0] = true;
	vis[n + 1] = true;

	int left = n, cur = 1;
	while (true) {
		// 풍선 터뜨리기
		vis[cur] = true;
		// 터뜨린 풍선 출력
		cout << cur << " ";
		// 남은 풍선 개수 업데이트
		--left;
		// 풍선을 다 터뜨렸다면 종료
		if (left == 0) break;
		// 이동 방향 확인
		bool dir = k[cur] > 0 ? true : false;
		// 이동 횟수 확인
		int num = (dir ? 1 : -1) * k[cur] % left;
		// 오른쪽
		if (dir) {
			if (num) cur = moving(true, cur, num);
			else cur = moving(false, cur, 1);
		}
		// 왼쪽
		else {
			if (num) cur = moving(false, cur, num);
			else cur = moving(true, cur, 1);
		}
	}

	return 0;
}