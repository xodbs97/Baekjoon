#include <bits/stdc++.h>
using namespace std;

int  az[30];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(az, az + 30, -1);

	string s;
	cin >> s;

	int idx = 0;
	for (char c : s) {
		if (az[c - 'a'] == -1) az[c - 'a'] = idx; // 첫 등장
		++idx;
	}
	for (int i = 0; i < 26; i++) cout << az[i] << " ";

	return 0;
}