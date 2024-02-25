#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll ans = 0;

	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; ++i) {
		ll n = s[i] - 'a' + 1;
		for (int j = 0; j < i; ++j) {
			n *= 31;
			n %= 1234567891;
		}
		ans += n;
		ans %= 1234567891;
	}
	cout << ans;

	return 0;
}