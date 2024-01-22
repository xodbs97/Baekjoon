#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

    vector<pair<int, int>> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int ts, te;
		cin >> ts >> te;
		v.push_back({ te,ts });
	}
	sort(v.begin(), v.end());

	int num = v[0].X;
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (v[i].Y >= num) {
			num = v[i].X;
			++cnt;
		}
	}
	cout << cnt;

	return 0;
}