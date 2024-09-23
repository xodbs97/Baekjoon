#include <bits/stdc++.h>

using namespace std;

// 변의 길이
int n;
// 종이의 색깔과 검사한 영역
vector<vector<int>> paper(130, vector<int>(130));
vector<vector<bool>> checked(130, vector<bool>(130));
// 각 색깔을 가진 색종이의 개수
int ans0, ans1;

void check(const int& x, const int& y, const int& s) {
	const int color = paper[x][y];
	bool same = true;
	bool accept = true;
	// 색종이 밖을 나가는 경우
	if (x + s > n || y + s > n) accept = false;
	// 가능한 사이즈를 넘긴 경우
	if (x % s || y % s) accept = false;
	// 테스트 가능한 경우
	if (accept) {
		for (int i = x; i < x + s; ++i) {
			for (int j = y; j < y + s; ++j) {
				if (color != paper[i][j]) {
					same = false;
					break;
				}
			}
			if (!same) break;
		}
	}
	else same = false;

	if (same) check(x, y, s * 2);
	else {
		for (int i = x; i < x + s / 2; ++i) {
			for (int j = y; j < y + s / 2; ++j) {
				checked[i][j] = true;
			}
		}
		if (color) ++ans1;
		else ++ans0;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> paper[i][j];
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (!checked[i][j]) check(i, j, 1);
	cout << ans0 << "\n" << ans1;

	return 0;
}