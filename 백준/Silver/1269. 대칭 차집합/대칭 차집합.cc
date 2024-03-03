#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	set<int> a;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		a.insert(num);
	}

	int dup = 0;
	for (int i = 0; i < m; ++i) {
		int num;
		cin >> num;
		if (a.find(num) != a.end()) ++dup;
	}
	cout << n + m - dup * 2;

	return 0;
}