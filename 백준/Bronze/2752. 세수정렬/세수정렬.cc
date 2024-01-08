#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v;
	for (int i = 0; i < 3; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	for (auto i : v) {
		cout << i << " ";
	}

	return 0;
}