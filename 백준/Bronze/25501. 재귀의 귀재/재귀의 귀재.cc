#include <bits/stdc++.h>

using namespace std;

int cnt;

int isPalindrome(const string& s, int l, int r) {
	++cnt;
	if (l >= r) return 1;
	if (s[l] != s[r]) return 0;

	return isPalindrome(s, l + 1, r - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;

		cnt = 0;
		int res = isPalindrome(str, 0, (int)str.length() - 1);

		cout << res << " " << cnt << "\n";
	}

	return 0;
}