#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll ans = 0;
	stack<ll> st;

	int n; // 빌딩 개수
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll h;
		cin >> h;
		while (st.size()) {
			if (st.top() > h) {
				ans += st.size();
				break;
			}
			else st.pop();
		}
		st.push(h);
	}
	cout << ans;

	return 0;
}