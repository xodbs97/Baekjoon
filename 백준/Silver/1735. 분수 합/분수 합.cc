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

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int gcd1 = b > d ? gcd(b, d) : gcd(d, b);

	int up = a * d / gcd1 + c * b / gcd1;
	int down = b * d / gcd1;
	int gcd2 = up > down ? gcd(up, down) : gcd(down, up);
	cout << up / gcd2 << " " << down / gcd2;

	return 0;
}