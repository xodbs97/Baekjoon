#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// n마리를 잡았을 때 얻는 경험치: n * (n + 1) / 2
// 레벨 l을 도달하기 위한 최소 요구 경험치: l * (l - 1)
// 정확한 값을 위해 sqrt 사용 불가, 따라서 이분탐색으로 진행
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;

		ll exp = n * (n + 1) / 2;
		ll be = 1, mid = 0, en = 1000000000;
		while (be + 1 < en) {
			mid = (be + en) / 2;

			if (mid * (mid - 1) > exp) en = mid;
			else be = mid;
		}
		cout << be << "\n";
	}

	return 0;
}