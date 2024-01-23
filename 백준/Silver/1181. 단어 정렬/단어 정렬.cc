#include <bits/stdc++.h>
using namespace std;

bool srt(const string& a, const string& b) {
	if (a.size() != b.size()) return a.size() < b.size();
	return a < b;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<string> v;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end(), srt);

	cout << v[0] << "\n";
	for (int i = 1; i < n; i++) {
		if (v[i] == v[i - 1]) continue;
		cout << v[i] << "\n";
	}

	return 0;
}