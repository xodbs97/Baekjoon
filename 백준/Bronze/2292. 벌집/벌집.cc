#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	// 최소 방의 길이, 최소 방의 길이를 충족하는 가장 큰 방의 번호
	int mul = 1, num = 1;
	while (true) {
		if (n <= num) break;
		num += mul * 6;
		++mul;
	}
	cout << mul;

	return 0;
}