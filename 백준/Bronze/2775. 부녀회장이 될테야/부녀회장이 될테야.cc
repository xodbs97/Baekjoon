#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<int>> apart(15, vector<int>(15));
	for (int i = 1; i <= 14; ++i) apart[0][i] = i;
	for (int i = 1; i <= 14; ++i) {
		for (int j = 1; j <= 14; ++j) {
			if (j == 1) apart[i][j] = apart[i - 1][j];
			else apart[i][j] = apart[i][j - 1] + apart[i - 1][j];
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int k, n;
		cin >> k >> n;
		cout << apart[k][n] << "\n";
	}

	return 0;
}