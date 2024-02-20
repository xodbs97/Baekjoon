#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (true) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a + b + c == 0) return 0;

		if (a + b <= c || b + c <= a || a + c <= b) {
			cout << "Invalid\n";
			continue;
		}
		if (a == b && b == c && c == a) {
			cout << "Equilateral\n";
			continue;
		}
		if (a == b || b == c || c == a) {
			cout << "Isosceles\n";
			continue;
		}
		cout << "Scalene\n";
	}
    
	return 0;
}