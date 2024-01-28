#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		int i = 0;
		bool impo = true;
		while ((x + m * i) <= m * n) {
			int div = (x + m * i) % n;
			if ((div == 0 && y == n) || div == y) {
				cout << (x + m * i) << "\n";
				impo = false;
				break;
			}
			++i;
		}
		if (impo) cout << -1 << "\n";
	}

	return 0;
}