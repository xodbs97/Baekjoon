#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

pair<int, int> p[100005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; // 1 ~ 100 000
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i].X >> p[i].Y;
	sort(p, p + n);
	for (int i = 0; i < n; i++) cout << p[i].X << " " << p[i].Y << "\n";

	return 0;
}