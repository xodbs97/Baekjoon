#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> board(100, vector<bool>(100));

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int n;
	cin >> n;

	int ans = 0;
	int times = (int)s.length() - 1;
	for (char c : s) {
		int adder;
		if (c >= '0' && c <= '9') adder = c - '0';
		else adder = c - 'A' + 10;
		for (int i = 0; i < times; ++i) adder *= n;
		ans += adder;
		--times;
	}
	cout << ans;

	return 0;
}