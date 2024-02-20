#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	if (a + b + c != 180) {
		cout << "Error";
		return 0;
	}
	if (a == 60 && b == 60 && c == 60) {
		cout << "Equilateral";
		return 0;
	}
	if (a == b || b == c || a == c) {
		cout << "Isosceles";
		return 0;
	}
	cout << "Scalene";
	return 0;
}