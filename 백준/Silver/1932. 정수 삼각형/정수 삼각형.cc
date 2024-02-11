#include <bits/stdc++.h>

using namespace std;

// 삼각형의 값들 저장하는 벡터
vector<int> v;
// 삼각형 원소의 최대 원소번호
int maxNum;
// f층일 경우에 f층의 시작 번호를 반환해준다.
int cnt(int f) {
	return (f * f - f) / 2;
}
// 답들을 저장할 벡터. 최종 정답은 0번째 원소에 들어가있다.
vector<int> ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 층 높이
	int n;
	cin >> n;
	// 삼각형을 이루는 원소들의 개수
	maxNum = cnt(n + 1);
	v.resize(maxNum);
	ans.resize(n);
	for (int i = 0; i < maxNum; ++i) cin >> v[i];
	for (int i = 0; i < n; ++i) ans[i] = v[maxNum - n + i];
	while (--n) { // n - 1 ~ 1까지 반복
		int fn = cnt(n);
		for (int i = 0; i < n; ++i) ans[i] = max(ans[i], ans[i + 1]) + v[fn + i];
	}
	cout << ans[0];

	return 0;
}