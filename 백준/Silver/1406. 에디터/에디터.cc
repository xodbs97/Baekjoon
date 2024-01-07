#include <bits/stdc++.h>

using namespace std;

int main() {
	string str;
	cin >> str;
	list<char> l;
	for (auto c : str) {
		l.push_back(c);
	}
	auto t = l.end();

	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string cmd;
		getline(cin, cmd);
		if (cmd.front() == 'L') {
			t = t == l.begin() ? t : --t;
		}
		else if (cmd.front() == 'D') {
			t = t == l.end() ? t : ++t;
		}
		else if (cmd.front() == 'B') {
			t = t == l.begin() ? t : l.erase(--t);
		}
		else if (cmd.front() == 'P') {
			l.insert(t, cmd.back());
		}
	}

	for (auto c : l) {
		cout << c;
	}
}