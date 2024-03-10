#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll a, b;

int checking(ll n, int idx) {
	if (n > b) return 1000;
	if (n == b) return idx;

	return min(checking(n * 2, idx + 1), checking(n * 10 + 1, idx + 1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;
	int cnt = checking(a, 1);
	cout << (cnt > 999 ? -1 : cnt);

	return 0;
}