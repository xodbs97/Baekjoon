#include <bits/stdc++.h>
using namespace std;

int n, m;
int num[100005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	cin >> num[1];
	for (int i = 2; i <= n; i++) {
		int j;
		cin >> j;
		num[i] = num[i - 1] + j;
	}

	int i, j;
	for (int k = 0; k < m; k++) {
		cin >> i >> j;
		cout << num[j] - num[i - 1] << "\n";
	}

	return 0;
}