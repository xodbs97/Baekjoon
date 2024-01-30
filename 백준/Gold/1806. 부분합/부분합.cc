#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, s; // 수열의 길이, 최소로 만족해야 할 부분합의 크기
	cin >> n >> s;
	vector<int> v(n); // 크기가 n인 벡터
	for (int i = 0; i < n; i++) cin >> v[i];
	if (v[0] >= s) {
		cout << 1;
		return 0;
	}

	int ans = 100005, sum = 0;
	int le = 0, ri = 0;
	while (le < n) { // left 증가하는 곳
		if (le > 0) sum -= v[le - 1]; // 맨 처음을 제외하고 부분합은 왼쪽이 1씩 이동해야함
		while (ri < n) { // right 증가하는 곳. ri가 n이 되면 더이상 부분합이 커질 이유가 없음
			if (sum >= s) { // 부분합이 s보다 크거나 같을 때
				// 현재 ans에 저장되어있는 값과 지금 ri - le + 1의 값 중 더 작은 값으로 ans의 값 저장
				ans = min(ans, ri - le);
				break;
			}
			sum += v[ri]; // 0부터 더해지기 시작. v[n-1]이 더해지면 더이상 더해지는 일은 없음
			++ri;
		}
		if (ri == n && sum >= s) ans = min(ans, ri - le);
		++le;
	}
	cout << (ans == 100005 ? 0 : ans);
	return 0;
}