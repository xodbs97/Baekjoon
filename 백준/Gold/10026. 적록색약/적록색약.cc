#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

char pg[105][105];
bool ch1[105][105], ch2[105][105];
int dx[4]{ 0,1,0,-1 }, dy[4]{ 1,0,-1,0 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int j = 0;
		for (char c : s) {
			pg[i][j++] = c;
		}
	}

	int ans1 = 0, ans2 = 0;
	queue<pair<int, int>> q1, q2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!ch1[i][j]) {
				q1.push({ i,j });
				ch1[i][j] = true;
				char c = pg[i][j];
				while (q1.size()) {
					for (int k = 0; k < 4; k++) {
						int px = q1.front().X + dx[k], py = q1.front().Y + dy[k];
						if (px < 0 || px >= n || py < 0 || py >= n) continue;
						if (ch1[px][py]) continue;
						if (pg[px][py] != c) continue;
						q1.push({ px,py });
						ch1[px][py] = true;
					}
					q1.pop();
				}
				++ans1;
			}
			if (!ch2[i][j]) {
				q2.push({ i,j });
				ch2[i][j] = true;
				char c = pg[i][j];
				while (q2.size()) {
					for (int k = 0; k < 4; k++) {
						int px = q2.front().X + dx[k], py = q2.front().Y + dy[k];
						if (px < 0 || px >= n || py < 0 || py >= n) continue;
						if (ch2[px][py]) continue;
						if (c == 'B' && pg[px][py] != 'B')  continue;
						if ((c == 'R' || c == 'G') && pg[px][py] == 'B')  continue;
						q2.push({ px,py });
						ch2[px][py] = true;
					}
					q2.pop();
				}
				++ans2;
			}
		}
	}
	cout << ans1 << " " << ans2;

	return 0;
}