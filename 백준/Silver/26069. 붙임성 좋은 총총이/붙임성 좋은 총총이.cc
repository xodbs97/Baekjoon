#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	set<string> yes;
	yes.insert("ChongChong");

	int n;
	cin >> n;
	while (n--) {
		string s1, s2;
		cin >> s1 >> s2;

		// 댄서인가?
		bool d1 = yes.find(s1) != yes.end();
		bool d2 = yes.find(s2) != yes.end();
		// 둘 중에 한명이라도 댄서라면
		if (d1 || d2) {
			yes.insert(s1);
			yes.insert(s2);
		}
	}
	cout << yes.size();

	return 0;
}