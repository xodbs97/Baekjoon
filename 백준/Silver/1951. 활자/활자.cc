#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll do1(ll n) {
	return n;
}
ll do2(ll n) {
	return do1(9) + (n - 9) * 2;
}
ll do3(ll n) {
	return do2(99) + (n - 99) * 3;
}
ll do4(ll n) {
	return do3(999) + (n - 999) * 4;
}
ll do5(ll n) {
	return do4(9999) + (n - 9999) * 5;
}
ll do6(ll n) {
	return (do5(99999) + (n - 99999) * 6) % 1234567;
}
ll do7(ll n) {
	return (do6(999999) + (n - 999999) * 7) % 1234567;
}
ll do8(ll n) {
	return (do7(9999999) + (n - 9999999) * 8) % 1234567;
}
ll do9(ll n) {
	return (do8(99999999) + (n - 99999999) * 9) % 1234567;
}
ll do10(ll n) {
	return (do9(999999999) + (n - 999999999) * 10) % 1234567;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin >> n;

	if (n < 10) cout << do1(n);
	else if (n < 100) cout << do2(n);
	else if (n < 1000) cout << do3(n);
	else if (n < 10000) cout << do4(n);
	else if (n < 100000) cout << do5(n);
	else if (n < 1000000) cout << do6(n);
	else if (n < 10000000) cout << do7(n);
	else if (n < 100000000) cout << do8(n);
	else if (n < 1000000000) cout << do9(n);
	else cout << do10(n);

	return 0;
}