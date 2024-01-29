#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());

	int mn = 2100000000;
	int j = 1;
	for (int i = 0; i < n; i++) {
		for (; j < n; j++) {
			if (v[j] - v[i] >= m) {
				mn = min(mn, v[j] - v[i]);
				break;
			}
		}
	}
	cout << mn;

	return 0;
}