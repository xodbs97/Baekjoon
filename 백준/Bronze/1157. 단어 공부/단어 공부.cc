#include <bits/stdc++.h>
using namespace std;

int az[30];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	for (char c : s) {
		if (c - 'a' >= 0) ++az[c - 'a'];
		else ++az[c - 'A'];
	}

	int mx = 0;
	for (int i = 0; i < 26; i++) mx = max(mx, az[i]);

	int cnt = 0, idx = 0;
	for (int i = 0; i < 26; i++) {
		if (mx == az[i]) {
			++cnt;
			idx = i;
		}
		if (cnt > 1) {
			cout << "?";
			return 0;
		}
	}
	cout << (char)(idx + 'A');

	return 0;
}