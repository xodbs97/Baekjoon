#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n1, n2;
	cin >> n1 >> n2;
	int n3 = n1 * (n2 % 10);
	n2 /= 10;
	int n4 = n1 * (n2 % 10);
	n2 /= 10;
	int n5 = n1 * (n2 % 10);
	cout << n3 << "\n" << n4 << "\n" << n5 << "\n" << n3 + n4 * 10 + n5 * 100;

	return 0;
}