#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	set<string> ss;
	for (int i = 0; i < s.size(); ++i) {
		for (int j = i; j < s.size(); ++j) {
			ss.insert(s.substr(i, j - i + 1));
		}
	}
	cout << ss.size();

	return 0;
}