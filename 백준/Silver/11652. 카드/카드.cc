#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<ll> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll nn;
		cin >> nn;
		v.push_back(nn);
	}
	sort(v.begin(), v.end());

	int cnt = 0, max_cnt = 0;
	ll num = v[0], max_num = 0;
	for (ll nn : v) {
		if (nn == num) ++cnt;
		else {
			if (cnt > max_cnt) {
				max_num = num;
				max_cnt = cnt;
			}
			num = nn;
			cnt = 1;
		}
	}
	if (cnt > max_cnt) max_num = num;
	cout << max_num;

	return 0;
}