#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; ++i) v[i] = i;
	while (m--) {
		int a, b;
		cin >> a >> b;
		swap(v[a], v[b]);
	}
	for (int i = 1; i <= n; ++i) cout << v[i] << " ";

	return 0;
}