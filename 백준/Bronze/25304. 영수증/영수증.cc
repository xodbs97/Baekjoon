#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x;
	cin >> x;
	int n;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		x -= a * b;
	}
	if (x) cout << "No";
	else cout << "Yes";

	return 0;
}