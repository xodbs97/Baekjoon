#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	if (k == 0 || k == n) {
		cout << 1;
		return 0;
	}
	if (k == 1 || k == n - 1) {
		cout << n;
		return 0;
	}

	vector<int> v1(n + 1, 0);
	vector<int> v2(n + 1, 0);
	v1[1] = 2, v1[2] = 1;
	for (int i = 3; i <= n; i++) {
		v2[1] = i, v2[i] = 1;
		for (int j = 2; j < i; j++) {
			v2[j] = v1[j - 1] + v1[j] >= 10007 ? (v1[j - 1] + v1[j]) % 10007 : v1[j - 1] + v1[j];
		}
		v1.swap(v2);
	}
	cout << v1[k];

	return 0;
}