#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int ans = 0;
	for (int i = 1; i * i <= n; ++i) ++ans;
	cout << ans;

	return 0;
}