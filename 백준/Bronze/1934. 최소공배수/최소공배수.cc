#include <bits/stdc++.h>

using namespace std;

// a가 b보다 무조건 더 크게 집어넣자
int gcd(int a, int b) {
	if (a % b == 0) return b;
	return a > b ? gcd(b, a - b) : gcd(b, b - a);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int num = a > b ? gcd(a, b) : gcd(b, a);
		cout << a / num * b << "\n";
	}

	return 0;
}