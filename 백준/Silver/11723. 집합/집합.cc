#include <bits/stdc++.h>

using namespace std;

vector<bool> v(21);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m;
	cin >> m;
	string s;
	int n;
	while (m--) {
		cin >> s;
		if (s != "all" && s != "empty") cin >> n;
		if (s == "add") v[n] = true;
		else if (s == "remove") v[n] = false;
		else if (s == "check") cout << (v[n] ? 1 : 0) << "\n";
		else if (s == "toggle") v[n] = !v[n];
		else if (s == "all") for (int i = 1; i <= 20; ++i) v[i] = true;
		else for (int i = 1; i <= 20; ++i) v[i] = false;
	}

	return 0;
}