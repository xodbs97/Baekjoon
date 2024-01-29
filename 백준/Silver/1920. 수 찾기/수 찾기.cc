#include <bits/stdc++.h>
using namespace std;

int binary_search(const vector<int>& v, int num) {
	int left = 0, right = v.size() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (num == v[mid]) return 1;
		else if (num > v[mid]) left = mid + 1;
		else right = mid - 1;
	}
	return 0;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());

	int m;
	cin >> m;
	while (m--) {
		int num;
		cin >> num;
		cout << binary_search(v, num) << "\n";
	}

	return 0;
}