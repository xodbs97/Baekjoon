#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int cnt_ran(const vector<int>& v, int len) {
	int cnt = 0;
	for (int i = 0; i < (int)v.size(); i++) cnt += v[i] / len;
	return cnt;
}

int ran_len(const vector<int>& v, int n) {
	ll le = 1, ri = v[v.size() - 1];
	while (le <= ri) {
		int mid = (le + ri) / 2;
		if (cnt_ran(v, mid) < n) ri = (ll)mid - 1; // 길이 줄여보기
		else le = (ll)mid + 1; // 바로 mid를 출력하지 않고 최대의 ri 구하기
	}
	return ri;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k, n;
	cin >> k >> n;
	vector<int> v(k);
	for (int i = 0; i < k; i++) cin >> v[i];
	sort(v.begin(), v.end());

	cout << ran_len(v, n);

	return 0;
}