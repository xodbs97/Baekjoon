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

	int n;
	cin >> n;

	vector<int> dif(n - 1);

	int tree;
	cin >> tree;
	for (int i = 0; i < n - 1; ++i) {
		int num;
		cin >> num;
		dif[i] = num - tree;
		tree = num;
	}

	ll gcdNum = dif[0] > dif[1] ? gcd(dif[0], dif[1]) : gcd(dif[1], dif[0]);
	for (int i = 2; i < n - 1; ++i) {
		gcdNum = gcdNum > dif[i] ? gcd(gcdNum, dif[i]) : gcd(dif[i], gcdNum);
	}

	int ans = 0;
	for (int i : dif) ans += i / gcdNum - 1;
	cout << ans;

	return 0;
}