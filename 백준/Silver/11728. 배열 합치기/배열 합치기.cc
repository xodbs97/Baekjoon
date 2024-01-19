#include <bits/stdc++.h>
using namespace std;

int a[1000001], b[1000001], c[2000002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	int ai = 0, bi = 0;
	for (int i = 0; i < n + m; i++) {
		if (ai == n) c[i] = b[bi++];
		else if (bi == m)c[i] = a[ai++];
		else if (a[ai] > b[bi]) c[i] = b[bi++];
		else c[i] = a[ai++];
	}

	for (int i = 0; i < n + m; i++) {
		cout << c[i] << " ";
	}

	return 0;
}