#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> px, py;

	int n;
	cin >> n;
	while (n--) {
		int x, y;
		cin >> x >> y;
		px.push_back(x);
		py.push_back(y);
	}
	sort(px.begin(), px.end());
	sort(py.begin(), py.end());
	cout << (px[px.size() - 1] - px[0]) * (py[py.size() - 1] - py[0]);

	return 0;
}