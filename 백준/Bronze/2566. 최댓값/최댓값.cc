#include <bits/stdc++.h>

using namespace std;

int board[10][10];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int max = -1, x = 0, y = 0;
	for (int i = 1; i <= 9; ++i) for (int j = 1; j <= 9; ++j) {
		int num;
		cin >> num;
		if (num > max) {
			max = num;
			x = i;
			y = j;
		}
	}
	cout << max << "\n" << x << " " << y;

	return 0;
}