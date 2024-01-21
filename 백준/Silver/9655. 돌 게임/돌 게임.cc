#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int first = n % 4;
	cout << (first % 2 == 0 ? "CY" : "SK");

	return 0;
}