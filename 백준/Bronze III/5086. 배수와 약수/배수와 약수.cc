#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0) break;
		if (a < b) cout << (b % a ? "neither\n" : "factor\n");
		else cout << (a % b ? "neither\n" : "multiple\n");
	}

	return 0;
}