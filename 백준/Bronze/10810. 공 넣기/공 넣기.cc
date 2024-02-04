#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1);
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		for (int i = a; i <= b; ++i) v[i] = c;
	}
	for (int i = 1; i <= n; ++i) cout << v[i] << " ";

	return 0;
}