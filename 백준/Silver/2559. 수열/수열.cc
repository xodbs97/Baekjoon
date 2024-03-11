#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> v(n), a(n - k + 1);

	for (int i = 0; i < n; ++i) cin >> v[i];

	for (int i = 0; i < k; ++i) a[0] += v[i];

	for (int i = 1; i < n - k + 1; ++i) a[i] = a[i - 1] - v[i - 1] + v[i + k - 1];

	int answer = -999999999;
	for (auto i : a) answer = max(i, answer);
	cout << answer;

	return 0;
}