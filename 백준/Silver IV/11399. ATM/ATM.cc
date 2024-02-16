#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	sort(v.begin(), v.end());
	for (int i = 1; i < n; ++i) v[i] += v[i - 1];

	int ans = 0;
	for (int i = 0; i < n; ++i) ans += v[i];
	cout << ans;

	return 0;
}