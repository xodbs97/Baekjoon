#include <bits/stdc++.h>
using namespace std;

int dp[61][61][61];
int scv[3];

int func(int a) {
	if (a <= 0) return 0;

	return 1 + func(a - 9);
}
int func(int a, int b) {
	if (a <= 0) return func(b);
	if (b <= 0) return func(a);

	return 1 + min(func(a - 9, b - 3), func(a - 3, b - 9));
}
int func(int a, int b, int c) {
	if (a <= 0) return func(b, c);
	if (b <= 0) return func(a, c);
	if (c <= 0) return func(a, b);

	int& x = dp[a][b][c];
	if (x) return x;

	x = 1000;
	x = min(x, 1 + func(a - 9, b - 3, c - 1));
	x = min(x, 1 + func(a - 9, b - 1, c - 3));
	x = min(x, 1 + func(a - 3, b - 9, c - 1));
	x = min(x, 1 + func(a - 3, b - 1, c - 9));
	x = min(x, 1 + func(a - 1, b - 9, c - 3));
	x = min(x, 1 + func(a - 1, b - 3, c - 9));

	return x;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> scv[i];

	if (n == 1) cout << func(scv[0]);
	else if (n == 2) cout << func(scv[0], scv[1]);
	else cout << func(scv[0], scv[1], scv[2]);

	return 0;
}