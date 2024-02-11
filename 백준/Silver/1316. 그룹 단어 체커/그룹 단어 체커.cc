#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		if (s.length() == 1) {
			++ans;
			continue;
		}

		vector<bool> v(30, false);
		bool b = true;
		char c = s[0];
		v[c - 'a'] = true;
		for (int i = 1; i < s.length(); ++i) {
			if (s[i] == c) continue;
			else c = s[i];
			if (v[c - 'a']) {
				b = false;
				break;
			}
			else v[c - 'a'] = true;
		}
		if (b) ++ans;
	}
	cout << ans;

	return 0;
}