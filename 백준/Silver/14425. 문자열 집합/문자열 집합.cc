#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	set<string> ss;

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		ss.insert(s);
	}
    
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;
		if (ss.find(s) != ss.end()) ++ans;
	}
	cout << ans;

	return 0;
}