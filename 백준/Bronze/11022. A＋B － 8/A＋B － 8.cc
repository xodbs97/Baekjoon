#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int a, b;
		cin >> a >> b;
		cout << "Case #" << i << ": " << a << " + " << b << " = " << a + b << "\n";
	}

	return 0;
}