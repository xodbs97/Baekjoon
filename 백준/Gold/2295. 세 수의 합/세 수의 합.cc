#include <bits/stdc++.h>
using namespace std;

bool find_k(const vector<int>& v, const vector<int>& t, int idx) {
	int k = v[idx];
	for (int i = 0; i <= idx - 1; i++) {
		int left = 0, right = (int)t.size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (v[i] + t[mid] > k) right = mid - 1;
			else if (v[i] + t[mid] < k) left = mid + 1;
			else return true;
		}
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());

	vector<int> two;
	for (int i = 0; i < (int)v.size(); i++) {
		for (int j = i; j < (int)v.size(); j++) {
			two.push_back(v[i] + v[j]);
		}
	}
	sort(two.begin(), two.end());

	for (int k = n - 1; k > 0; k--) {
		if (find_k(v, two, k)) {
			cout << v[k];
			return 0;
		}
	}

	return 0;
}