#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, v;
	cin >> a >> b >> v;

	int le = 0, ri = 1000000000;
	int days;
	while (true) {
		days = (le + ri) / 2;
		if (le >= ri) break;
		ll h = (ll)(a - b) * days + a;
		if (h < (ll)v) le = days + 1;
		else ri = days;
	}
	cout << days + 1;

	return 0;
}