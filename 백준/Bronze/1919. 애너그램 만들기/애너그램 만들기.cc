#include <bits/stdc++.h>
using namespace std;

string a, b;
int cnt[30][2]; // a~z 개수

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;
	for (auto c : a) ++cnt[c - 'a'][0];
	for (auto c : b) ++cnt[c - 'a'][1];
	int ans = 0;
	for (int i = 0; i < 26; i++) ans += cnt[i][0] > cnt[i][1] ? cnt[i][0] - cnt[i][1] : cnt[i][1] - cnt[i][0];
	cout << ans;

	return 0;
}