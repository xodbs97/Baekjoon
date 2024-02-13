#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 테스트 케이스 개수
	int t;
	cin >> t;
	while (t--) {
		// 문서의 개수, 해당 문서가 놓여져 있는 위치
		int n, m;
		cin >> n >> m;
		// 문서의 우선순위를 저장하는 벡터
		vector<int> doc(n, 0);
		// 전체 문서들의 우선순위 종류를 저장하는 벡터
		vector<bool> priority(10, false);
		// 해당 우선순위를 가진 문서의 개수를 저장하는 벡터
		vector<int> cnt(10, 0);
		for (int i = 0; i < n; ++i) {
			// n개의 원소를 저장
			cin >> doc[i];
			// 해당 우선순위를 가진 문서의 존재를 확인
			priority[doc[i]] = true;
			// 해당 우선순위를 가진 문서의 개수를 1 증가시킴
			++cnt[doc[i]];
		}
		// 요구하는 문서를 찾았을 때 참으로 수정
		bool find = false;
		// 출력될 정답을 저장하는 변수
		int ans = 0;
		// 문서를 탐색하기 위한 인덱싱 변수
		int idx = 0;
		// 높은 우선순위부터 탐색
		for (int i = 9; i >= 1; --i) {
			// 해당 우선순위를 가진 문서일 경우에 탐색
			if (priority[i]) {
				while (cnt[i]) {
					// 해당 인덱스의 문서가 출력해야 할 문서일 때
					if (doc[idx] == i) {
						// 인쇄 횟수 증가
						++ans;
						// 출력하고 싶던 문서일 경우
						if (idx == m) {
							find = true;
							break;
						}
						// 해당 우선순위를 가진 출력해야 할 문서의 개수가 1 감소
						--cnt[i];
					}
					// doc[n]은 곧 doc[0]
					idx = idx == n - 1 ? 0 : idx + 1;
				}
			}
			if (find) break;
		}
		cout << ans << "\n";
	}

	return 0;
}