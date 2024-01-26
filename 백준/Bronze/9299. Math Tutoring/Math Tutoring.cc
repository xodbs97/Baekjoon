#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int r; // repeat
	cin >> r;
	for (int i = 1; i <= r; i++) {
		int n;
		cin >> n; // highest exponent
		cout << "Case " << i << ": " << n - 1 << " ";
		for (int j = n; j >= 0; j--) {
			int c;
			cin >> c;
			if (j) cout << j * c << " ";
		}
		cout << "\n";
	}

	return 0;
}