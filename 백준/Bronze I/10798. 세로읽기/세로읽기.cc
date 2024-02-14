#include <bits/stdc++.h>

using namespace std;

vector<string> v;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int mx = 0;
	for (int i = 0; i < 5; ++i) {
		string s;
		cin >> s;
		v.push_back(s);
		mx = max(mx, (int)s.length());
	}

	for (int i = 0; i < mx; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (v[j].length() > i) cout << v[j][i];
		}
	}

	return 0;
}