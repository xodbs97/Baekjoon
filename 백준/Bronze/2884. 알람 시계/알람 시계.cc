#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int h, m;
	cin >> h >> m;
	if (m - 45 >= 0) cout << h << " " << m - 45;
	else cout << (h == 0 ? 23 : h - 1) << " " << m + 15;

	return 0;
}