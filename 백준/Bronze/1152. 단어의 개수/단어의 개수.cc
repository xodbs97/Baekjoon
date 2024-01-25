#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ans = 0;

	string s;
	getline(cin, s);

	stringstream ss;
	ss.str(s);
	while (ss >> s)++ans;
	cout << ans;

	return 0;
}