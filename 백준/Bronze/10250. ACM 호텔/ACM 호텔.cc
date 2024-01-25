#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, h, w, n;
	cin >> t;
	while (t--) {
		cin >> h >> w >> n;

		int floar = n % h;
		int room = n / h;
		if (floar) ++room;
		else floar = h;

		int ans = floar * 100 + room;
		cout << ans << "\n";
	}

	return 0;
}