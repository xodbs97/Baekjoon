#include <bits/stdc++.h>

using namespace std;

int s[1005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	sort(s, s + n);

	int max = s[n - 1];
	double sum = 0;
	for (int i = 0; i < n; i++) sum += (double)s[i] / max * 100;
	cout << sum / n;

	return 0;
}