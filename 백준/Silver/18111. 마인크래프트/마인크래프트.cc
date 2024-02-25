#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, b;
	cin >> n >> m >> b;

	vector<int> land(n * m);
	for (int i = 0; i < n * m; ++i) cin >> land[i];

	int time = 2000000000, height = 0;
	for (int floor = 0; floor <= 256; ++floor) {
		int put = 0, dig = 0;
		for (int idx = 0; idx < n * m; ++idx) {
			int dif = floor - land[idx];
			if (dif > 0) put += dif;
			else if (dif < 0) dig -= dif;
		}

		if (put > dig + b) break;

		if (time >= put + dig * 2) {
			time = put + dig * 2;
			height = floor;
		}
	}
	cout << time << " " << height;

	return 0;
}