#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// a가 b보다 무조건 더 크게 집어넣자
ll gcd(ll a, ll b) {
	if (a % b == 0) return b;
	return a > b ? gcd(b, a - b) : gcd(b, b - a);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll a, b;
	cin >> a >> b;
	ll num = a > b ? gcd(a, b) : gcd(b, a);
	cout << a / num * b;

	return 0;
}