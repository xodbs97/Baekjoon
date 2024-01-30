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

	int mx = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			int sumij = v[i] + v[j];
			if (sumij > m) break;
			for (int k = j + 1; k < n; k++) {
				int sumijk = sumij + v[k];
				if (sumijk > m) break;
				mx = max(mx, sumijk);
			}
		}
	}
	cout << mx;
	return 0;
}