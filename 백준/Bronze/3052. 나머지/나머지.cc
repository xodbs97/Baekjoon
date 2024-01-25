#include <bits/stdc++.h>
using namespace std;

int  k[45];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	for (int i = 0; i < 10; i++) {
		cin >> n;
		++k[n % 42];
	}

	int ans = 0;
	for (int i = 0; i < 42; i++) if (k[i]) ++ans;
	cout << ans;

	return 0;
}