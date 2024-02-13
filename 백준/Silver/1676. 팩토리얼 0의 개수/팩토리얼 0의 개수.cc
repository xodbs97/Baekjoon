#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	// 0이 하나 만들어지기 위해서는 5가 1개 필요하다.
	int ans = 0;
	for (int i = 1; i*5 <= n; ++i) {
		int num = i;
		// 25, 125 등을 대비
		while (true) {
			++ans;
			if (num % 5) break;
			num /= 5;
		}
	}
	cout << ans;

	return 0;
}