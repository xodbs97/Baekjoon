#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int aa = stoi(a), bb = stoi(b);
	cout << (aa > bb ? aa : bb);

	return 0;
}