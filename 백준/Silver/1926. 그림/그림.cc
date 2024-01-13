#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second

int board[502][502];
bool vis[502][502];
int n, m;
int dx[4]{ 1,0,-1,0 };
int dy[4]{ 0,1,0,-1 };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> board[i][j];

	queue<pair<int, int>> q;
	int pic_num = 0, pic_size = 0, max = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		if (board[i][j] == 1 && vis[i][j] == 0) {
			++pic_num;
			pic_size = 0;
			q.push({ i,j });
			vis[i][j] = true;
			while (q.size()) {
				pair<int, int> p = q.front();
				++pic_size;
				q.pop();
				for (int k = 0; k < 4; k++) {
					int nx = p.X + dx[k];
					int my = p.Y + dy[k];
					if (nx < 0 || nx >= n || my < 0 || my >= m) continue;
					if (board[nx][my] != 1 || vis[nx][my]) continue;
					q.push({ nx,my });
					vis[nx][my] = true;
				}
			}
		}
		if (pic_size > max) max = pic_size;
	}
	cout << pic_num << "\n" << max;

	return 0;
}