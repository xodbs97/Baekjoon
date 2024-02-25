#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}

	int cut = round((double)n * 0.15);

	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	sort(v.begin(), v.end());

	int sum = 0;
	for (int i = cut; i < n - cut; ++i) sum += v[i];

	int avg = round((double)sum / (n - cut * 2));
	cout << avg;

	return 0;
}