#include <bits/stdc++.h>
using namespace std;

int n, k; // 참가 학생 수, 한 방의 최대 인원 수
int grade[8][2];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int s, y;
		cin >> s >> y;
		++grade[y][s];
	}
	int ans = 0;
	for (int i = 1; i <= 6; i++) {
		for (int j = 0; j <= 1; j++) {
			if (grade[i][j] == 0) continue;
			ans += grade[i][j] % k == 0 ? grade[i][j] / k : grade[i][j] / k + 1;
		}
	}
	cout << ans;

	return 0;
}