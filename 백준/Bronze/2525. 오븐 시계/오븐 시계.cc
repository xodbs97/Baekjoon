#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	int m = (b + c >= 60) ? ((b + c) % 60) : (b + c);
	int ah = (b + c) / 60;
	int h = (a + ah >= 24) ? ((a + ah) % 24) : (a + ah);
	cout << h << " " << m;

	return 0;
}