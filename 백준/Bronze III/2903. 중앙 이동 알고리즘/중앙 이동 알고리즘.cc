#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	// 각 변에 마주하는 사각형의 개수
	int side=1;
	for (int i = 0; i < n; ++i) side *= 2;
	cout << (side + 1) * (side + 1);

	return 0;
}