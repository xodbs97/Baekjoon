#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define X first
#define Y second

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> vm;
	while (n--) {
		int m, v;
		cin >> m >> v;
		vm.push_back({ v,m });
	}
	sort(vm.begin(), vm.end(), greater());

	multiset<int> backpack;
	while (k--) {
		int c;
		cin >> c;
		backpack.insert(c);
	}

	ll ans = 0;
	for (pair p : vm) {
		if (backpack.empty()) break;
		if (backpack.lower_bound(p.Y) != backpack.end()) {
			ans += p.X;
			backpack.erase(backpack.find(*backpack.lower_bound(p.Y)));
		}
	}
	cout << ans;
	return 0;
}