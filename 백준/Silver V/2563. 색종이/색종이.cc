#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> board(100, vector<bool>(100));

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int horizontal, vertical;
		cin >> horizontal >> vertical;
		for (int y = vertical; y < vertical + 10; ++y) for (int x = horizontal; x < horizontal + 10; ++x) board[y][x] = true;
	}

	int ans = 0;
	for (int i = 0; i < 100; ++i) for (int j = 0; j < 100; ++j) if (board[i][j]) ++ans;
	cout << ans;

	return 0;
}