#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<bool> q(n, false);
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		if (num) continue;
		q[i] = true;
	}

	vector<int> v;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		if (q[i]) v.push_back(num);
	}

	if (!v.empty()) reverse(v.begin(), v.end());

	int k;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	for (int i = 0; i < k; ++i) cout << v[i] << " ";

	return 0;
}