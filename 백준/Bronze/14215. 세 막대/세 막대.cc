#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	if (a + b <= c) cout << a + b + a + b - 1;
	else if (b + c <= a) cout << b + c + b + c - 1;
	else if (a + c <= b) cout << a + c + a + c - 1;
	else cout << a + b + c;

	return 0;
}