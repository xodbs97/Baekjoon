#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		// 동심원
		if (x1 == x2 && y1 == y2) {
			if (r1 == r2) cout << -1 << "\n";
			else cout << 0 << "\n";
			continue;
		}

		int len = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2); // 거리의 제곱
		if ((len >= r1 * r1) && (len >= r2 * r2)) { // 중심간 거리가 제일 긴 경우
			if (len > (r1 * r1 + 2 * r1 * r2 + r2 * r2)) cout << 0 << "\n"; // 세 선분으로 삼각형을 만들지 못할 때
			else if (len == (r1 * r1 + 2 * r1 * r2 + r2 * r2)) cout << 1 << "\n"; // 두 선분의 길이의 합이 나머지 하나의 선분과 같을 때
			else cout << 2 << "\n"; // 세 선분이 삼각형을 이룰 때
		}
		else { // r1이나 r2 둘 중 하나가 긴 경우
			if (len < (r1 * r1 - 2 * r1 * r2 + r2 * r2)) cout << 0 << "\n";
			else if (len == (r1 * r1 - 2 * r1 * r2 + r2 * r2)) cout << 1 << "\n";
			else cout << 2 << "\n";
		}
	}

	return 0;
}