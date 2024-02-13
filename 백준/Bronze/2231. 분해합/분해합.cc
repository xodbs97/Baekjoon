#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int ans = 0;

	int n;
	cin >> n;
	// 아무리 생성자가 작아도 해당 수와의 차이가 9 * 6 = 54 보다 커질 수는 없다.
    // 입력으로 주어지는 수가 최대 7자리 수이기 때문이다.
	for (int i = n - 54 > 0 ? n - 54 : 1; i < n; ++i) {
		int check_num = i;
		int divNum = i;
		while (divNum) {
			check_num += divNum % 10;
			divNum /= 10;
		}
		if (check_num == n) {
			ans = i;
			break;
		}
	}
	cout << ans;

	return 0;
}