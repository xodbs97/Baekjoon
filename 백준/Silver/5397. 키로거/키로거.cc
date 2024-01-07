#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	while (n--) {
		list<char> l;
		auto t = l.begin();
		string s;
		cin >> s;
		for (auto c : s) {
			if (c == '-') {
				if (t != l.begin()) {
					t = l.erase(--t);
				}
			}
			else if (c == '<') {
				if (t != l.begin()) {
					--t;
				}
			}
			else if (c == '>') {
				if (t != l.end()) {
					++t;
				}
			}
			else {
				l.insert(t, c);
			}
		}
		for (auto c : l) {
			cout << c;
		}
		cout << "\n";
	}

	return 0;
}