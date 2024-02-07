#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	string s1 = s;
	reverse(s1.begin(), s1.end());
	cout << (s1 == s ? 1 : 0);

	return 0;
}