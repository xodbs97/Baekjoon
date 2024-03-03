#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a1, a0, c, n0;
	cin >> a1 >> a0 >> c >> n0;
	cout << (c < a1 || c * n0 < a1 * n0 + a0 ? 0 : 1);

	return 0;
}