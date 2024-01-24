#include <bits/stdc++.h>
using namespace std;

int n; // 테스트 케이스 수
string s[1005]; // 원본
string f[1005]; // 재배치된 문자열

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i] >> f[i];

	for (int i = 0; i < n; i++) {
		sort(s[i].begin(), s[i].end());
		sort(f[i].begin(), f[i].end());
		cout << (s[i] == f[i] ? "Possible" : "Impossible") << "\n";
	}

	return 0;
}