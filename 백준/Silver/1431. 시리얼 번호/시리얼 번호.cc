#include <bits/stdc++.h>
using namespace std;

int n;

bool cmp(const string& a, const string& b) {
	if (a.size() != b.size()) return a.size() < b.size();
	int sa = 0, sb = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= '0' && a[i] <= '9') sa += a[i] - '0';
		if (b[i] >= '0' && b[i] <= '9') sb += b[i] - '0';
	}
	if (sa != sb) return sa < sb;
	return a < b;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<string> v;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		v.push_back(str);
	}

	sort(v.begin(), v.end(), cmp);
	for (string str : v) cout << str << "\n";

	return 0;
}