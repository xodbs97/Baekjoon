#include <bits/stdc++.h>

using namespace std;

// 수의 존재 확인
vector<bool> exist(8005);
// 그 수의 빈도 확인
vector<int> cnt(8005);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	// 산술 평균을 위한 변수
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		// 수 입력
		int num;
		cin >> num;
		sum += num;
		exist[num + 4000] = true;
		++cnt[num + 4000];
	}
	// 산술평균 출력. 반올림을 해야하는 경우는 나머지의 2배가 n보다 클 경우이다.
	if (sum >= 0) cout << (sum % n * 2 > n ? sum / n + 1 : sum / n) << "\n";
	else cout << ((sum * -1) % n * 2 > n ? ((sum * -1) / n + 1) * -1 : ((sum * -1) / n) * -1) << "\n";
	// 중앙값 출력 및 최빈값에 해당하는 수량 확인
	int mid = 0, max_cnt = 0;
	bool yet = true;
	for (int i = 0; i <= 8000; ++i) {
		if (exist[i]) {
			mid += cnt[i];
			max_cnt = max(max_cnt, cnt[i]);
			if (yet && mid > n / 2) {
				cout << i - 4000 << "\n";
				yet = false;
			}
		}
	}
	// 최빈값 출력
	int ans = -1;
	bool checked = false;
	for (int i = 0; i <= 8000; ++i) {
		if (exist[i] && cnt[i] == max_cnt) {
			if (!checked) {
				ans = i - 4000;
				checked = true;
				continue;
			}
			if (checked) {
				ans = i - 4000;
				break;
			}
		}
	}
	cout << ans << "\n";
	// 범위 출력
	int v1, v2;
	for (int i = 0; i <= 8000; ++i) if (exist[i]) {
		v1 = i;
		break;
	}
	for (int i = 8000; i >= 0; --i) if (exist[i]) {
		v2 = i;
		break;
	}
	cout << v2 - v1;

	return 0;
}